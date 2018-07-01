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

Plugin::Plugin() {

}

Plugin::~Plugin() {

}
/*
PluginCpp::PluginCpp() :Plugin() {
	this->preInitialisation = [this](InitialisationEvent e)->void {
		this->plg->preInitialisation(e);
	};
	this->Initialisation = [this](InitialisationEvent e)->void {
		this->plg->Initialisation(e);
	};
	this->postInitialisation = [this](InitialisationEvent e)->void {
		this->plg->postInitialisation(e);
	};
}
*/
PluginPython::PluginPython() :Plugin() {
	this->preInitialisation = [this](InitialisationEvent e)->void {
		
	};
	this->Initialisation = [this](InitialisationEvent e)->void {
		this->plg->Initialisation(e);
	};
	this->postInitialisation = [this](InitialisationEvent e)->void {
		this->plg->postInitialisation(e);
	};
}
