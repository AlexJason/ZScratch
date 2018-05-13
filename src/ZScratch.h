/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	ZScratch.h
 * @author	AlexCui
 * @date	May, 2018
 * @details	This is requires of main function.
*/

//This needs Visual Studio
#ifdef _WIN64
#  ifdef _DEBUG
#    include "../lib/x64d/pragma.h"
#  else
#    include "../lib/x64/pragma.h"
#  endif
#else
#  ifdef _DEBUG
#    include "../lib/x86d/pragma.h"
#  else
#    include "../lib/x86/pragma.h"
#  endif
#endif
