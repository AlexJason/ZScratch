/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	FileIO.cpp
 * @author	Alex Cui
 * @date	March, 2018
 * @details	The module for loading local files.
*/

#include "FileIO.h"

#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cassert>
#include <io.h>
#include <direct.h>

#include "../../lib/include/tinyxml/tinyxml.h"
#include "../../lib/include/ziputil/zip.h"
#include "../../lib/include/ziputil/unzip.h"
#include "../scratch/Scratch.h"
#include "String.h"
#include "AppArgu.h"

using namespace zscratch::plugin::cpp;

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

	int a, b;//The temp variable only used in next do...while loop.
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
		a = 0;
		b = 0;
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



void FileIO::LoadExtension(std::vector<IScratchPlugin*> &ext) {
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
		IScratchPlugin*(*c)()  = (IScratchPlugin*(*)())GetProcAddress(lib, MAKEINTRESOURCEA(1));
		IScratchPlugin* plugin = c();
		ext.push_back(plugin);
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


File::File(std::string path) {
	this->path = path;
}

std::vector<std::string> File::getFileList(std::string fmt) {
	std::vector<std::string> find;
	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(fmt.c_str(), &findData);
	if (handle == -1) {
		find.clear();
	}
	else {
		int a, b;//The temp variable only used in next do...while loop.
		do {
			a = 0, b = 0;
			if ((a = strcmp(findData.name, ".") != 0) && (b = strcmp(findData.name, "..") != 0))
				find.push_back(findData.name);
		} while (_findnext(handle, &findData) == 0);
	}
	_findclose(handle);

	return find;
}

