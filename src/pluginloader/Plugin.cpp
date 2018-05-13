/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	Plugin.cpp
 * @author	Alex Cui
 * @date	May, 2018
 * @details	The instance of plugin.
*/

#include "Plugin.h"

using namespace zscratch::plugin::cpp;

Plugin::Plugin(zscratch::plugin::cpp::IScratchPlugin *t) {
	this->plg = new IScratchPlugin(*t); //Shalldow copy
}

Plugin::~Plugin() {
	delete this->plg;
}
