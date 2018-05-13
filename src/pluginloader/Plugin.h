/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	Plugin.h
 * @author	Alex Cui
 * @date	May, 2018
 * @details	The instance of plugin.
*/

#pragma once
#ifndef ZSCRATCH_UTIL_PLUGIN
#define ZSCRATCH_UTIL_PLUGIN

#include "../plugin/cpp/IScratchPlugin.h"

enum class PluginAPI {
	CPP,	//C++ 17 or higher
	CS,		//.NET 4.5 or higher
	JAVA,	//Java 9 or higher
	PYTHON,	//Python 3.6 or higher
	LUA		//Lua 5.3 or higher
};

class Plugin {
public:
	Plugin() = default;
	Plugin(zscratch::plugin::cpp::IScratchPlugin*);
	~Plugin();

	zscratch::plugin::cpp::IScratchPlugin* plg;

	//JSON:
	std::string extid;
	std::string title;
	std::string description;
	std::string version;
	std::vector<std::string> author;
	std::string email;
	std::string website;
	std::string require;
	std::string sdk;
	std::string system;
	std::string updateUrl;
	std::string downloadUrl;
};

#endif

