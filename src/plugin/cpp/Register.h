/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	Register.h
 * @author	Alex Cui
 * @date	May, 2018
 * @details	Object registion.
*/

#pragma once
#ifndef PDK_REGISTER
#define PDK_REGISTER

#include "dlldef.h"

#include <vector>

#include "IScratchBlock.h"
#include "IScratchChooseBox.h"

NAMESPACE_
extern DLLAPI std::vector<IScratchBlock*> regBlock;
extern DLLAPI std::vector<IScratchChooseBox*> regChooseBox;
_NAMESPACE

#endif

