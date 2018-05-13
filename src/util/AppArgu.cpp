/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	AppArgu.cpp
 * @author	AlexCui
 * @date	April, 2018
 * @details	This is the configuration of the program.
*/

#include "AppArgu.h"

//default argument settings

AppArgu::AppArgu() {
	path = std::string();
	test = false;
	console = false;
	printPluginName = false;
	printPluginVersion = false;
}


AppArgu::~AppArgu()
{
}
