/** ScratchSpec.h - ZScratch
*	Copyright(C) 2017-2018 Alex Cui
*
*	This program is free software : you can redistribute it and/or modify
*	it under the terms of the GNU Affero General Public License as
*	published by the Free Software Foundation, either version 3 of the
*	License, or (at your option) any later version.
*
*	This program is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
*	GNU Affero General Public License for more details.
*
*	You should have received a copy of the GNU Affero General Public License
*	along with this program.If not, see <https://www.gnu.org/licenses/>.
*/

/**
* ScratchSpec.h
* Alex Cui, March 2018
*
* The static class that defines the commands, parts, and blocks.
*/

#pragma once
#ifndef SCRATCH_SPEC
#define SCRATCH_SPEC
#include <string>
#include <vector>
#include "ScratchValue.h"
class ScratchSpec {
public:
	struct Category {
		Category() {};
		Category(unsigned int id, std::string name, unsigned long color) {
			this->id = id;
			this->name = name;
			this->color = color;
		}
		unsigned int id;
		std::string name;
		unsigned long color;
	};
	
	struct Command {
		std::string name;
		std::string type;
		unsigned int category;
		std::string command;
		std::vector<ScratchValue> defaultValue;
	};
public:
	static std::vector<Category> category;
	static std::vector<Command> command;
public:
	ScratchSpec();
	~ScratchSpec();
};
#endif

