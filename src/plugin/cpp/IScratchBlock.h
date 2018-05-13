/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	IScratchBlock.h
 * @author	Alex Cui
 * @date	April, 2018
 * @details	Class of Blocks.
*/

#pragma once
#ifndef PDK_SCRATCHBLOCK
#define PDK_SCRATCHBLOCK
#include <string>
#include <vector>

#include "IScratchBlockItem.h"
NAMESPACE_
class IScratchBlock {
public:
	std::string title;

	//Temps:
	std::vector<IScratchBlockItem*> compiled;
	bool hasCompiled;
public:
	virtual std::vector<IScratchBlockItem*> compileBlock();

	IScratchBlock();
	~IScratchBlock();
};
_NAMESPACE
#endif
