/** ScratchValue.h - ZScratch
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
* ScratchValue.h
* Alex Cui, March 2018
*
* The class that none-type variable value for scratch.
*/

#pragma once
#ifndef SCRATCH_VALUE
#define SCRATCH_VALUE
#include <string>
class ScratchValue {
public:
	enum Type {
		INTEGER,
		FLOAT,
		STRING,
		BOOLEAN
	};
public:
	std::string value;
public:
	ScratchValue();
	~ScratchValue();

	long asInt();//This'll be changed into ScratchNumber class.
	double asFloat();//This'll be deleted.
	std::string asString();
	bool asBool();
};
#endif

