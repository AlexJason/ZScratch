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
#include "../../lib/include/python/Python.h"

#include <string>
#include <vector>
#include <functional>

enum class PluginAPI {
	CPP,	//C++ 17 or higher
	CS,		//.NET 4.5 or higher
	JAVA,	//Java 9 or higher
	PYTHON,	//Python 3.6 or higher
	LUA		//Lua 5.3 or higher
};

class Plugin {
public:
	Plugin();
	~Plugin();

	//Plugin:
	std::function<void(InitialisationEvent)> preInitialisation;
	std::function<void(InitialisationEvent)> Initialisation;
	std::function<void(InitialisationEvent)> postInitialisation;

	//API:
	PluginAPI api;

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

	//GET/SET
	virtual PluginAPI getAPI() = 0;
};

/*
class PluginCpp :public Plugin {
public:
	PluginCpp() {}
	~PluginCpp() {}
	IScratchPlugin* plg;

	virtual PluginAPI getAPI() { return PluginAPI::CPP; }
};
*/

class PluginPython :public Plugin {
public:
	PluginPython();
	~PluginPython();
	PyObject *pModule;
	PyObject *pDict;
	PyObject *py_preInitialisation;
	PyObject *py_Initialisation;
	PyObject *py_postInitialisation;

	virtual PluginAPI getAPI() { return PluginAPI::PYTHON; }
};

#endif

