/** Scratch.h - ZScratch
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
* Scratch.h
* Alex Cui, March 2018
*
* This is the main class of the program.
*/

#pragma once
#ifndef ZSCRATCH_CLASS
#define ZSCRATCH_CLASS
#include <Windows.h>
#include <vector>
#include "ScratchStage.h"
#include "../interface/cpp/ScratchExtension.h"
#include "../util/AppArgu.h"

#define __winA "win32"
#ifdef _WIN64
#define __win "x64"
#elif defined(_WIN32)
#define __win "x86"
#endif

#ifdef _DEBUG
#define __lib "_d.lib"
#else
#define __lib ".lib"
#endif

#pragma comment(lib, "lib/tinyxml/" __winA "/tinyxmlSTL" __lib)
#pragma comment(lib, "lib/ziputil/" __win "/ziputil" __lib)
//#pragma comment(lib, "lib/python/" __win "/python3" __lib)
//#pragma comment(lib, "lib/python/" __win "/python36" __lib)

class Scratch {
public:
	//Windows
	LPCWSTR ClassName;
	LPCWSTR WindowTitle;

	HWND WindowHandle;
	HWND ConsoleHandle;
	HINSTANCE ProgramInstance;

	ATOM RegisterWindowClass();
	BOOL CreateMainWindow();
	DECLSPEC_DEPRECATED
	WPARAM MessageLoop();
	WPARAM MessageLoop(int);
	LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	//Scratch
	std::string log;
	ScratchStage stage;
	std::vector<ScratchExtension*> ext;
	AppArgu argu;

	void Log(std::string str);
	int AppMain(int argc, char **argv);
	void AppRelease();
	void InstallExtension();

	Scratch();
	~Scratch();
};

extern Scratch sc;

#endif


