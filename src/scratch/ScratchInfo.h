/** ScratchInfo.h - ZScratch
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
* ScratchInfo.h
* Alex Cui, March 2018
*
* The basic infomation of the project.
*/

#pragma once
#ifndef SCRATCH_INFO
#define SCRATCH_INFO
#include <string>
class ScratchInfo {
public:
	bool videoOn;
	unsigned int spriteCount;
	unsigned int scriptCount;
	std::string userAgent;
	std::string flashVersion;
	std::string swfVersion;
public:
	ScratchInfo();
	~ScratchInfo();
};
#endif

