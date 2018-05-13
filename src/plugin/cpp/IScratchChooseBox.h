/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	IScratchBlock.cpp
 * @author	Alex Cui
 * @date	April, 2018
 * @details	Class of Blocks.
*/

#pragma once
#ifndef PDK_ISCRATCHCHOOSEBOX
#define PDK_ISCRATCHCHOOSEBOX

#include "dlldef.h"

#include <vector>
NAMESPACE_
class DLLAPI IScratchChooseBox {
protected:
	std::vector<std::string> item;
public:
	IScratchChooseBox();
	~IScratchChooseBox();
	size_t size();
	void add(std::string item);
	void del(std::string item);
	size_t isExist(std::string item);
};

void RegisterObject(IScratchChooseBox *obj);
_NAMESPACE
#endif
