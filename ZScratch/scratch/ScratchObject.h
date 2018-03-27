/** ScratchObject.h - ZScratch
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
* ScratchObject.h
* Alex Cui, March 2018
*
* The class of scratch object.
*/

#pragma once
#ifndef SCRATCH_OBJECT
#define SCRATCH_OBJECT
#include <string>
class ScratchObject {
public:
	std::string objName;
	int scripts;
	int sounds;
	int costumes;
	unsigned int currentCostumeIndex;


	ScratchObject();
	~ScratchObject();
};
#endif
