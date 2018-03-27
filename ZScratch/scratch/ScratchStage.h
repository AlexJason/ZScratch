/** ScratchStage.h - ZScratch
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
* ScratchStage.h
* Alex Cui, March 2018
*
* The class of stage.
*/

#pragma once
#ifndef SCRATCH_STAGE
#define SCRATCH_STAGE
#include "ScratchObject.h"
#include "ScratchSprite.h"
#include "ScratchInfo.h"
#include <string>
#include <vector>
class ScratchStage :
	public ScratchObject {
public:
	std::string penLayerMD5;
	unsigned int penLayerID;
	unsigned int tempoBPM;
	double videoAlpha;
	std::vector<ScratchSprite> children;
	ScratchInfo info;
public:
	ScratchStage();
	~ScratchStage();
};
#endif

