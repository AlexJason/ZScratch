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
#include <iostream>

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
using namespace std;

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
	ret = new PluginPython();
	this->LoadPluginJson(name, ret, true);
	PluginPython *plg = dynamic_cast<PluginPython*>(ret);
	if (plg == nullptr)
		return nullptr;
	string entry = name + ".plugin";
	plg->pModule = PyImport_Import(PyUnicode_FromString(entry.c_str()));
	if (!plg->pModule) {
		cerr << "Plugin Error: Module import error" << endl;
		return nullptr;
	}
	plg->pDict = PyModule_GetDict(plg->pModule);
	if (!plg->pDict) {
		cerr << "Plugin Error: Dict get error" << endl;
		return nullptr;
	}
	plg->py_preInitialisation = PyDict_GetItemString(plg->pDict, "preInitialisation");
	if (!plg->py_preInitialisation) {
		cerr << "Plugin Error: preInitialisation not found" << endl;
		return nullptr;
	}
	plg->py_Initialisation = PyDict_GetItemString(plg->pDict, "Initialisation");
	if (!plg->py_Initialisation) {
		cerr << "Plugin Error: Initialisation not found" << endl;
		return nullptr;
	}
	plg->py_postInitialisation = PyDict_GetItemString(plg->pDict, "postInitialisation");
	if (!plg->py_postInitialisation) {
		cerr << "Plugin Error: postInitialisation not found" << endl;
		return nullptr;
	}
	return ret;
}

void PluginLoader::LoadPluginJson(string name, Plugin*& plg, bool print) {
	try {
		string plgPath = "./temp/plugin/" + name.substr(0, name.size() - 4);
		ifstream json(plgPath + "/info.json", ios::in | ios::_Nocreate);
		if (!json.is_open())
			throw PLError_JsonError(plgPath + ": cannot find json", true);

		Json::Value root;
		Json::Reader reader;
		Json::Value value;
		if (!reader.parse(json, root))
			throw PLError_JsonError(plgPath + ": isnot a json file", true);

		if (!root["extid"].isString())
			throw PLError_JsonError(plgPath + ": json.extid must be string", true);
		plg->extid = root["extid"].asString();
		plg->title = root["title"].isString() ? root["title"].asString() : plg->extid;
		plg->description = root["description"].asString();
		if (!root["sdk"].isString())
			throw PLError_JsonError(plgPath + ": json.sdk must exist", true);
		auto sdk = root["sdk"].asString();
		if (sdk != "python")
			throw PLError_JsonError(plgPath + ": " + sdk + "is not allowed as api", true);
		plg->sdk = sdk;
		/*
		if (sdk == "c++")
			//plg->api = PluginAPI::CPP;
			throw PLError_JsonError(plgPath + ": c++ is not allowed as api", true);
		else if (sdk == "c#")
			//plg->api = PluginAPI::CS;
			throw PLError_JsonError(plgPath + ": c# is not allowed as api", true);
		else if (sdk == "java")
			//plg->api = PluginAPI::JAVA;
			throw PLError_JsonError(plgPath + ": java is not allowed as api", true);
		else if (sdk == "python")
			plg->api = PluginAPI::PYTHON;
		else if (sdk == "lua")
			//plg->api = PluginAPI::LUA;
			throw PLError_JsonError(plgPath + ": lua is not allowed as api", true);
		*/
		value = root["author"];
		if (!value.isArray())
			throw PLError_JsonError(plgPath + ": json.author must be array", true);
		for (int i = 0; i < (int)value.size(); i++)
			plg->author.push_back(value[i].asString());
	}
	catch (PLError_JsonError t) {
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
