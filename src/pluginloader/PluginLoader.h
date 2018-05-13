/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	PluginLoader.h
 * @author	Alex Cui
 * @date	May, 2018
 * @details	Load resources from plugin.
*/

#pragma once
#ifndef ZSCRATCH_PLUGINLOADER_PLUGINLOADER
#define ZSCRATCH_PLUGINLOADER_PLUGINLOADER

#include <vector>
#include <string>
#include <map>

#include "..\plugin\cpp\IScratchPlugin.h"
#include "..\scratch\Scratch.h"
#include "Plugin.h"

class PluginLoader {
public:
	std::vector<Plugin> plugin;
private:
	std::map<PluginAPI, std::string> tmpSP;
public:
	PluginLoader(Scratch *);
	~PluginLoader();

	Scratch *sc;

	std::vector<std::string> SearchPlugin(std::string path);
	PluginAPI GetPluginAPI(std::ifstream info_json);

	std::vector<Plugin> LoadPlugin();
private:
	Plugin LoadPlugin_CPP(std::string name);
	void LoadPluginJson(std::string name, Plugin& plg, bool print = false);
};

#endif
