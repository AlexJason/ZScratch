/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	IScratchBlockItem.h
 * @author	Alex Cui
 * @date	April, 2018
 * @details	Class of Block's subitem.
*/

#pragma once
#ifndef PDK_SCRATCHBLOCKITEM
#define PDK_SCRATCHBLOCKITEM

#include "dlldef.h"

#include <string>
NAMESPACE_
enum class ItemType { TextLabel, CircleInput, RectInput, BoolInput };
class DLLAPI IScratchBlockItem {
public:
	ItemType type;
	std::string value;

	//IScratchBlockItem();
	//~IScratchBlockItem();
};
_NAMESPACE
#endif
