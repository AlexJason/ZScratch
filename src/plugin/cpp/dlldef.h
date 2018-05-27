/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	dlldef.h
 * @author	Alex Cui
 * @date	April, 2018
 * @details	Defines some marcos for dll import/export.
*/

#pragma once
#ifndef PDK_DLLDEF
#define PDK_DLLDEF

#if defined(_DLL) && !defined(DLLAPI)
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

#pragma warning(disable:4251)

#define NAMESPACE_ namespace zscratch::plugin::cpp {
#define _NAMESPACE }


#endif
