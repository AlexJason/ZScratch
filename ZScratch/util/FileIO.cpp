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

#ifdef UNICODE
#undef UNICODE
#endif
#include <Windows.h>
#include "../lib/tinyxml/include/tinyxml.h"
#include "../lib/ziputil/include/zip.h"
#include "../lib/ziputil/include/unzip.h"

#include <io.h>
#include <iostream>

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
		if (findData.attrib & _A_SUBDIR
			&& strcmp(findData.name, ".") == 0
			&& strcmp(findData.name, "..") == 0
			)
			fofind.push_back(findData.name);
		else
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
}

void FileIO::LoadTranslator() {
	auto path = getPath("Locale");
	TiXmlDocument *file = new TiXmlDocument("./config/locale.xml");
	file->LoadFile();
	TiXmlElement *root = file->RootElement();
	TiXmlNode *node = nullptr;

}



void FileIO::LoadExtension(std::vector<ScratchExtension*> &ext) {
	std::string loadPath = getPath("Plugin");
	std::vector<std::string> extlist = getFileList(loadPath);
	
	for (auto c : extlist) {
		std::string extp = (loadPath + '\\') + c;
		HZIP hz = OpenZip(extp.c_str(), 0);
		ZIPENTRY ze;
		GetZipItem(hz, -1, &ze);
		int numitems = ze.index;
		for (int zi = 0; zi < numitems; zi++) {
			ZIPENTRY ze;
			GetZipItem(hz, zi, &ze);
			UnzipItem(hz, zi, ze.name);
		}
		CloseZip(hz);
	}
}

bool FileIO::ExsistExtension()
{
	return false;
}

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}
