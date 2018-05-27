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
#include "../plugin/cpp/IScratchPlugin.h"

using namespace zscratch::plugin::cpp;


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

PluginAPI PluginLoader::GetPluginAPI(std::ifstream info_json) {
	
	return PluginAPI::CPP;
}

std::vector<Plugin> PluginLoader::LoadPlugin() {
	std::vector<Plugin> ret;
	for (const auto &c : this->tmpSP) {
		Plugin plg = LoadPlugin_CPP(c);
		ret.push_back(plg);
	}
	return ret;
}

Plugin PluginLoader::LoadPlugin_CPP(std::string name) {
	Plugin ret;
	this->LoadPluginJson(name, ret, true);

	//HMODULE lib = LoadLibraryA(("./temp/plugin/" + name + "/plugin.dll").c_str());
	//IScratchPlugin*(*c)() = (IScratchPlugin*(*)())GetProcAddress(lib, MAKEINTRESOURCEA(1));
	//IScratchPlugin* plugin = c();
	//ret.plg = plugin;
	return ret;
}

void PluginLoader::LoadPluginJson(std::string name, Plugin& plg, bool print) {
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
		plg.extid = root["extid"].asString();
		plg.title = root["title"].isString() ? root["title"].asString() : plg.extid;
		plg.description = root["description"].asString();
		if (!root["sdk"].isString())
			throw PLError_ApiError(plgPath + ": json.sdk must exist", true);
		plg.sdk = root["sdk"].asString();
		value = root["author"];
		if (!value.isArray())
			throw PLError_JsonError(plgPath + ": json.author must be array", true);
		for (int i = 0; i < value.size(); i++)
			plg.author.push_back(value[i].asString());
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
			"\n\tID   : " + plg.extid + 
			"\n\tName : " + plg.title +
			"\n\tAPI  : " + plg.sdk
		);
	}
}
