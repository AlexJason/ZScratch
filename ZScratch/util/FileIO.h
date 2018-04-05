/** FileIO.h - ZScratch
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
* FileIO.h
* Alex Cui, March 2018
*
* The class for loading the local files.
*/

#pragma once
#ifndef UTIL_FILELOADER
#define UTIL_FILELOADER
#include "../interface/cpp/ScratchExtension.h"
#include "../translate/Translate.h"
#include <string>

class FileIO {
public:
	std::vector<std::string> getFileList(std::string path);
	std::string getPath(std::string s);
	void LoadTranslator();
	void LoadExtension(std::vector<ScratchExtension*> &ext);
	bool ExsistExtension();
public:
	FileIO();
	~FileIO();
};
#endif
