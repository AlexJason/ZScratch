/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	PluginLoader.cpp
 * @author	Alex Cui
 * @date	May, 2018
 * @details	Load resources from plugin.
*/

#ifndef UNICODE
#define UNICODE
#endif

#include "PluginLoader.h"

#include <io.h>
#include <fstream>

//#include <Windows.h>

#include "PluginError.h"
#include "../util/String.h"
#include "../util/System.h"
#include "../util/File.h"
#include "../../lib/include/ziputil/unzip.h"
#include "../../lib/include/jsoncpp/json.h"
#include "../../lib/include/python/Python.h"
#include "../plugin/cpp/IScratchPlugin.h"

//using namespace zscratch::plugin::cpp;


PluginLoader::PluginLoader(Scratch * sc) {
	this->sc = sc;
	this->plugin.clear();
}

PluginLoader::~PluginLoader() {

}

std::vector<std::string> PluginLoader::UnzipPlugin() {
	std::vector<std::string> find = File("./plugin/").getFileList("*.zsp");

	std::wstring tempPath = L"./temp/plugin/";
	if (_waccess(L"./temp", 00) == -1)
		_wmkdir(L"./temp");
	if (_waccess(tempPath.c_str(), 00) == -1)
		_wmkdir(tempPath.c_str());
	//TODO: Unzip the zipped file to temp file.
	for (auto c : find) {
		std::wstring extp = L"./plugin/" + StringToWString(c);
		HZIP hz = OpenZip(extp.c_str(), 0);
		ZIPENTRY ze;
		GetZipItem(hz, -1, &ze);
		int numitems = ze.index;
		for (int zi = 0; zi < numitems; zi++) {
			ZIPENTRY ze;
			GetZipItem(hz, zi, &ze);
			std::wstring s = ze.name;
			if (*--s.end() == '/') {
				_wmkdir((tempPath + s).c_str());
				continue;
			}
			char *ibuf = new char[ze.unc_size];
			UnzipItem(hz, zi, ibuf, ze.unc_size);
			std::ofstream ofs((tempPath + ze.name).c_str(), std::ios::out);
			ofs.write(ibuf, ze.unc_size);
			ofs.flush();
			ofs.close();
			delete[] ibuf;
		}
		CloseZip(hz);
	}

	this->tmpSP = find;
	return find;
}

std::vector<Plugin*> PluginLoader::LoadPlugin() {
	std::vector<Plugin*> ret;
	for (const auto &c : this->tmpSP) {
		Plugin *plg = LoadPlugin(plg->api, c);
		ret.push_back(plg);
	}
	return ret;
}

Plugin* PluginLoader::LoadPlugin(PluginAPI api, std::string name) {
	Plugin *ret;
	this->LoadPluginJson(name, ret, true);
	switch (api) {
	case PluginAPI::CPP: {
		ret = new PluginCpp();
		PluginCpp *plg = dynamic_cast<PluginCpp*>(ret);
		if (plg == nullptr)
			break;
		HMODULE lib = LoadLibraryA(("./temp/plugin/" + name + "/plugin.dll").c_str());
		IScratchPlugin*(*LoadPlugin)() = (IScratchPlugin*(*)())GetProcAddress(lib, MAKEINTRESOURCEA(1));//call LoadPlugin()
		IScratchPlugin* plugin = LoadPlugin();
		plg->preInitialisation = [&plg](InitialisationEvent e) {
			plg->plg->preInitialisation(e);
		};
		plg->Initialisation = [&plg](InitialisationEvent e) {
			plg->plg->Initialisation(e);
		};
		plg->postInitialisation = [&plg](InitialisationEvent e) {
			plg->plg->postInitialisation(e);
		};
		break;
	}
	case PluginAPI::PYTHON: {
		ret = new PluginPython();
		PluginPython *plg = dynamic_cast<PluginPython*>(ret);
		if (plg == nullptr)
			break;
		if (!Py_IsInitialized())
			Py_Initialize();
		PyObject *pySys = PyImport_ImportModule("sys");
		PyObject *pySysPath = PyObject_GetAttrString(pySys, "path");
		PyObject *path = PyList_New(PyList_Size(pySysPath));
		PyObject *temp = path;
		PyList_Append(temp, PyUnicode_FromString(("./temp/plugin/" + name).c_str()));
		plg->pModule = PyImport_ImportModule("plugin");


		plg->preInitialisation = [](InitialisationEvent e) {

		};
		plg->Initialisation = [](InitialisationEvent e) {

		};
		plg->postInitialisation = [](InitialisationEvent e) {

		};
		plg->py_preInitialisation = PyObject_GetAttrString(plg->pModule, "preInitialisation");
		plg->py_Initialisation = PyObject_GetAttrString(plg->pModule, "Initialisation");
		plg->py_postInitialisation = PyObject_GetAttrString(plg->pModule, "postInitialisation");
		if (Py_IsInitialized())
			Py_Finalize();
		break;
	}
	default: {
		break;
	}
	}
	
	return ret;
}

void PluginLoader::LoadPluginJson(std::string name, Plugin*& plg, bool print) {
	std::string plgPath = "./temp/plugin/" + name.substr(0, name.size() - 4);
	std::ifstream json(plgPath + "/info.json", std::ios::in | std::ios::_Nocreate);
	if (!json.is_open())
		return;

	Json::Value root;
	Json::Reader reader;
	Json::Value value;
	if (!reader.parse(json, root))
		return;

	try {
		if (!root["extid"].isString())
			throw PLError_JsonError(plgPath + ": json.extid must be string", true);
		plg->extid = root["extid"].asString();
		plg->title = root["title"].isString() ? root["title"].asString() : plg->extid;
		plg->description = root["description"].asString();
		if (!root["sdk"].isString())
			throw PLError_ApiError(plgPath + ": json.sdk must exist", true);
		auto sdk = root["sdk"].asString();
		plg->sdk = sdk;
		if (sdk == "c++")
			plg->api = PluginAPI::CPP;
		else if (sdk == "c#")
			plg->api = PluginAPI::CS;
		else if (sdk == "java")
			plg->api = PluginAPI::JAVA;
		else if (sdk == "python")
			plg->api = PluginAPI::PYTHON;
		else if (sdk == "lua")
			plg->api = PluginAPI::LUA;
		value = root["author"];
		if (!value.isArray())
			throw PLError_JsonError(plgPath + ": json.author must be array", true);
		for (int i = 0; i < value.size(); i++)
			plg->author.push_back(value[i].asString());
	}
	catch (PLError_JsonError t) {
		this->sc->Log("PluginLoader ERROR: " + t.str);
		if (t.exit)
			return;
	}
	catch (PLError_ApiError t) {
		this->sc->Log("PluginLoader ERROR: " + t.str);
		if (t.exit)
			return;
	}
	static unsigned int i = 0;
	if (print) {
		std::stringstream str;
		str << i;
		std::string t;
		str >> t;
		this->sc->Log(
			"Plugin Info(" + t + ")" +
			"\n\tID   : " + plg->extid +
			"\n\tName : " + plg->title +
			"\n\tAPI  : " + plg->sdk
		);
	}
}
