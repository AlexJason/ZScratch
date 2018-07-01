/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	Scratch.cpp
 * @author	Alex Cui
 * @date	March, 2018
 * @details	This is the entry class of the program.
*/

#include "Scratch.h"

#include "..\util\Time.h"
#include "..\util\String.h"
#include "..\util\File.h"
#include "..\util\Console.h"
#include "..\util\AppArgu.h"
#include "..\util\Error.h"
#include "..\pluginloader\PluginLoader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

#include <direct.h>
#include <io.h>

DEFINE_ERROR(SCError_PlgError)

void Scratch::Log(std::string str) {
	std::string s = printTime() + str + '\n';
	log.append(s);
	std::cout << s;
}

int Scratch::AppMain(int argc, char **argv) {
	//Pre load logger file name
	getLogfileName();

	//Check arguments
	Log("Checking arguments.");
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--test"))
			argu.test = true;
		else if (strcmp(argv[i], "--console"))
			argu.console = true;
		else if (strcmp(argv[i], "-printPluginName"))
			argu.printPluginName = true;
		else if (strcmp(argv[i], "-printPluginVersion"))
			argu.printPluginVersion = true;
	}
	
	//Search plugins
	Log("Installing plugins.");
	//InstallExtension();
	this->InstallExtension();

	//Call IScratchExtension::PreInitialisation
	Log("Pre initialisate plugins.");
	for (auto &c : plugins)
		if (c->plg != nullptr)
			c->plg->preInitialisation(InitialisationEvent());

	//Call IScratchExtension::Initialisation
	Log("Initialisate plugins.");
	for (auto &c : plugins)
		if (c->plg != nullptr)
			c->plg->Initialisation(InitialisationEvent());

	//Call IScratchExtension::PostInitialisation
	Log("Post initialisate plugins.");
	for (auto &c : plugins)
		if (c->plg != nullptr)
			c->plg->postInitialisation(InitialisationEvent());

	return 0;
}

void Scratch::AppRelease() {
	_rmdir("./temp/");
	Log("Temp file has been deleted.");
	if (_access("./log", 00) == -1)
		_mkdir("./log");
	std::string f = getLogfileName();
	std::ofstream ofs(f, std::ios::out);
	ofs.write(log.c_str(), log.size());
	ofs.flush();
	ofs.close();
}

void Scratch::InstallExtension() {
	PluginLoader loader(this);
	loader.UnzipPlugin();
	this->plugins = loader.LoadPlugin();
}

Scratch::Scratch() {

}

Scratch::~Scratch() {
	AppRelease();
}
