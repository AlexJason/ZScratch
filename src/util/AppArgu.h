/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	AppArgu.h
 * @author	Alex Cui
 * @date	April, 2018
 * @details	This is the configuration of the program.
*/

#pragma once
#ifndef ZSCRATCH_UTIL_APPARGU
#define ZSCRATCH_UTIL_APPARGU

#include <functional>
#include <string>
class AppArgu {
public:
	std::string path;
	bool printPluginName;
	bool printPluginVersion;
	bool test;
	bool console;
public:
	AppArgu();
	~AppArgu();
};

#endif
