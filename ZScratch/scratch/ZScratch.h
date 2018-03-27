/** ZScratch.h - ZScratch
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
* ZScratch.h
* Alex Cui, March 2018
*
* This is the main class of the program.
*/

#pragma once
#ifndef ZSCRATCH_CLASS
#define ZSCRATCH_CLASS
#include <Windows.h>
class ZScratch {
public:
	static LPCWSTR ClassName;
	static LPCWSTR WindowTitle;

	static HWND WindowHandle;
	static HWND ConsoleHandle;
	static HINSTANCE ProgramInstance;

	static ATOM RegisterWindowClass();
	static BOOL CreateMainWindow();
	static WPARAM MessageLoop();
	static WPARAM MessageLoop(int);
	static LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	ZScratch();
	~ZScratch();
};
#endif


