/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	FileIO.h
 * @author	Alex Cui
 * @date	March, 2018
 * @details	The module for loading local files.
*/

#pragma once
#ifndef ZSCRATCH_UTIL_FILE_IO
#define ZSCRATCH_UTIL_FILE_IO

#include "../plugin/cpp/IScratchPlugin.h"
#include "../util/Translate.h"
#include <string>

class FileIO {
public:
	std::vector<std::string> getFileList(std::string path);
	std::string getPath(std::string s);
	void LoadTranslator();
	void LoadExtension(std::vector<IScratchPlugin*> &ext);
	bool ExsistExtension();
public:
	FileIO();
	~FileIO();
};

class File {
public:
	std::string path;
public:
	File() = default;
	File(std::string path);
	std::vector<std::string> getFileList(std::string fmt);
};

#endif
