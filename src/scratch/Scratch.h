/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	Scratch.h
 * @author	Alex Cui
 * @date	March, 2018
 * @details	This is the entry class of the program.
*/

#pragma once
#ifndef ZSCRATCH_SCRATCH_SCRATCH
#define ZSCRATCH_SCRATCH_SCRATCH

#include <Windows.h>
#include <vector>
#include "ScratchStage.h"
#include "../plugin/cpp/IScratchExtension.h"
#include "../util/AppArgu.h"

class Scratch {
public:
	//Scratch
	std::string log;
	ScratchStage stage;
	std::vector<IScratchExtension*> ext;
	AppArgu argu;

	void Log(std::string str);
	int AppMain(int argc, char **argv);
	void AppRelease();
	void InstallExtension();

	Scratch();
	~Scratch();
};

extern Scratch sc;

#endif


