/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	IScratchPlugin.h
 * @author	Alex Cui
 * @date	April, 2018
 * @details	Main class for plugin.
*/

#pragma once
#ifndef PDK_ISCRATCHPLUGIN
#define PDK_ISCRATCHPLUGIN

#include "dlldef.h"
NAMESPACE_
struct InitialisationEvent {

};

class IScratchPlugin {
public:
	IScratchPlugin() {}
	~IScratchPlugin() {}
	virtual void preInitialisation(InitialisationEvent e) {}
	virtual void Initialisation(InitialisationEvent e) {}
	virtual void postInitialisation(InitialisationEvent e) {}
};
_NAMESPACE
#endif
