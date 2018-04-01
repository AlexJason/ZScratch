/** FileLoader.cpp - ZScratch
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
* FileLoader.cpp
* Alex Cui, March 2018
*
* The class for loading the local files.
*/

#include "FileLoader.h"

#include "../lib/tinyxml/tinyxml.h"



std::string FileLoader::getPath(std::string s) {
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

void FileLoader::LoadTranslator() {
	auto path = getPath("Locale");
	TiXmlDocument *file = new TiXmlDocument("./config/locale.xml");
	file->LoadFile();
	TiXmlElement *root = file->RootElement();
	TiXmlNode *node = nullptr;

}

FileLoader::FileLoader()
{
}


FileLoader::~FileLoader()
{
}
