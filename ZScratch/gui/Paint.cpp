/** Paint.cpp - ZScratch
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
* Paint.cpp
* Alex Cui, March 2018
*
* The class for painting.
*/

#include "Paint.h"

void Paint::BeginPaint(HWND hwnd) {
	Paint::hwnd = hwnd;
	GetClientRect(hwnd, &rc);
	hdc = GetDC(hwnd);
	mdc = CreateCompatibleDC(hdc);
	hbmp = CreateCompatibleBitmap(hdc, rc.width(), rc.height());
	SelectObject(mdc, hbmp);
	ReleaseDC(hwnd, hdc);
}

void Paint::EndPaint(int x, int y) {
	hdc = GetDC(hwnd);
	BitBlt(hdc, rc.left, rc.top, rc.width(), rc.height(), mdc, rc.left, rc.top, SRCCOPY);
	ReleaseDC(hwnd, hdc);
	DeleteObject(mdc);
	DeleteObject(hbmp);
}

Paint::Paint() {

}


Paint::~Paint() {

}
