/** FileIO.cpp - ZScratch
*	Copyright(C) 2017-2018 Alex Cui
*
*	This program is free software : you can redistribute it and/or modify
*	it under the terms of the GNU Affero General Public License as
*	published by the Free Software Foundation, either version 3 of the
*	License, or (at your option) any later version.
*
*	This program is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
*	GNU Affero General Public License for more details.
*
*	You should have received a copy of the GNU Affero General Public License
*	along with this program.If not, see <https://www.gnu.org/licenses/>.
*/

/**
* FileIO.cpp
* Alex Cui, March 2018
*
* The class for loading the local files.
*/

#include "FileIO.h"

#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cassert>
#include <io.h>
#include <direct.h>

#include "../lib/tinyxml/include/tinyxml.h"
#include "../lib/ziputil/include/zip.h"
#include "../lib/ziputil/include/unzip.h"
#include "../scratch/Scratch.h"
#include "String.h"
#include "AppArgu.h"

std::vector<std::string> FileIO::getFileList(std::string path) {
	std::vector<std::string> fofind;
	std::vector<std::string> fifind;

	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(path.c_str(), &findData);
	if (handle == -1) {
		fofind.clear();
		fifind.clear();
		return fifind;
	}

	do {
		//======UNUSED:USE IF NEED TO SELECT THE FILE
		/*if (findData.attrib & _A_SUBDIR
			&& strcmp(findData.name, ".") == 0
			&& strcmp(findData.name, "..") == 0
			)
			fofind.push_back(findData.name);
		else if (strcmp(findData.name, ".") == 0
			&& strcmp(findData.name, "..") == 0
			)
			fifind.push_back(findData.name);*/
		//======INSTEAD:ONLY SELECT THE FILE EXTNAME SELECTED
		int a, b;
		if ((a = strcmp(findData.name, ".") != 0) && (b = strcmp(findData.name, "..") != 0))
			fifind.push_back(findData.name);
	} while (_findnext(handle, &findData) == 0);

	_findclose(handle);
	
	return fifind;
}

std::string FileIO::getPath(std::string s) {
	TiXmlDocument *file = new TiXmlDocument("./config/path.xml");
	file->LoadFile();
	TiXmlElement *root = file->RootElement();
	TiXmlNode *node = nullptr;
	for (node = root->IterateChildren("Path", node); \
		node->ToElement()->Attribute("name") != s.c_str() || node; \
		node = node->NextSibling("Path")) {	}
	if (!node)
		return "";
	return node->ToElement()->Attribute("path");
	return std::string();
}

void FileIO::LoadTranslator() {
	/*auto path = getPath("Locale");
	TiXmlDocument *file = new TiXmlDocument("./config/locale.xml");
	file->LoadFile();
	TiXmlElement *root = file->RootElement();
	TiXmlNode *node = nullptr;*/

}



void FileIO::LoadExtension(std::vector<IScratchExtension*> &ext) {
	std::vector<std::string> extlist = getFileList("./plugin/*.zsp");
	
	int w[] = {16, 8};

	std::wstring tempPath = L"./temp/plugin/";
	if (_waccess(L"./temp", 00) == -1)
		_wmkdir(L"./temp");
	if (_waccess(tempPath.c_str(), 00) == -1)
		_wmkdir(tempPath.c_str());
	//TODO: Unzip the zipped file to temp file.
	for (auto c : extlist) {
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

	//TODO: Read the file
	std::vector<std::string> exttemp = getFileList("./temp/plugin/*");
	for (auto c : exttemp) {
		std::string extpath = "./temp/plugin/" + c;
		std::ifstream json(extpath + "/info.json", std::ios::in | std::ios::_Nocreate);
		if (!json.is_open())
			continue;
		HMODULE lib = LoadLibraryA((extpath + "/plugin.dll").c_str());
		IScratchExtension*(*c)()  = (IScratchExtension*(*)())GetProcAddress(lib, MAKEINTRESOURCEA(1));
		IScratchExtension* plugin = c();
		ext.push_back(plugin);
	}

	//TODO: Load the class
	for (auto &c : ext) {
		c->construct();
	}
}

bool FileIO::ExsistExtension() {

	return false;
}

FileIO::FileIO() {

}


FileIO::~FileIO()
{
}
