/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	dlldef.h
 * @author	Alex Cui
 * @date	April, 2018
 * @details	This file defines marcos 'DLLAPI' for importing or exporting modules.
*/

#ifndef GUI_GLOBAL_H
#define GUI_GLOBAL_H

//DLLAPI definition
#if defined(GUI_LIBRARY)
#	define DLLAPI __declspec(dllexport)
#else
#	define DLLAPI __declspec(dllimport)
#endif

//Compiler definition
#if defined(_MSC_VER)
#	define COMPILE_CL
#elif defined(__gcc)
#	if defined(__cplusplus)
#		define COMPILE_GPP
#	else
#		define COMPILE_GCC
#	endif
#elif defined(_clang)
#	define COMPILE_CLANG
#endif

#endif // GUI_GLOBAL_H
