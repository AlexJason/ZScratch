/** Paint.h - ZScratch
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
* Paint.h
* Alex Cui, March 2018
*
* The class for painting.
*/

#pragma once
#ifndef GUI_PAINT
#define GUI_PAINT
#include <Windows.h>
#include "..\util\Rect.h"
class Paint {
public:
	static HWND hwnd;
	static Rect rc;
	static HDC hdc;
	static HDC mdc;
	static HBITMAP hbmp;
public:
	static void BeginPaint(HWND hwnd);
	static void EndPaint(int x = 0, int y = 0);
	Paint();
	~Paint();
};
#endif
