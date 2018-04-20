/** Scratch.cpp - ZScratch
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
* Scratch.cpp
* Alex Cui, March 2018
*
* This is the main class of the program.
*/

#include "Scratch.h"

#include "..\util\Paint.h"
#include "..\util\Time.h"
#include "..\util\String.h"
#include "..\util\FileIO.h"
#include "..\util\Console.h"
#include "..\util\AppArgu.h"

#include "..\interface\cpp_interface\ScratchEvent.h"
#include "..\interface\cpp_interface\RegisterInfo.h"

#include <fstream>
#include <sstream>

#include <direct.h>
#include <io.h>

Scratch sc;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return sc.WndProc(hwnd, msg, wParam, lParam);
}

ATOM Scratch::RegisterWindowClass() {
	WNDCLASSEXW wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = ::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = sizeof(LONG_PTR);
	wcex.hInstance = ProgramInstance;
	wcex.hbrBackground = NULL;
	wcex.lpszMenuName = NULL;
	wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wcex.hIcon = LoadIconW(wcex.hInstance, IDI_APPLICATION);
	wcex.hIconSm = wcex.hIcon;
	wcex.lpszClassName = ClassName;
	return RegisterClassExW(&wcex);
}

BOOL Scratch::CreateMainWindow() {
	WindowHandle = CreateWindowEx(0, ClassName, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, NULL, 0);
	if (!WindowHandle)
		return FALSE;
	return TRUE;
}

VOID Scratch::ShowMainWindow() {
	ShowWindow(WindowHandle, SW_NORMAL);
	UpdateWindow(WindowHandle);
	SendMessage(WindowHandle, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
}

DECLSPEC_DEPRECATED
WPARAM Scratch::MessageLoop() {
	MSG msg = { 0 };
	while (true) {
		if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
		else {
			continue;
		}
	}
	return msg.wParam;
}

WPARAM Scratch::MessageLoop(int) {
	MSG msg = { 0 };
	while (GetMessageW(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return msg.wParam;
}

LRESULT Scratch::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_PAINT: {
		static Paint p;
		p.BeginPaint(hwnd);
		HBRUSH hbr;
		hbr = CreateSolidBrush(0xffffff);
		FrameRect(p.mdc, &p.rc, hbr);
		FillRect(p.mdc, &p.rc, hbr);
		DeleteObject(hbr);
		ScratchGuiStruct sgs;
		sgs.hdc = p.mdc;
		sgs.hwnd = p.hwnd;
		sgs.rc = p.rc;
		for (auto c : RegScratchGui)
			c->onPaint(sgs);
		p.EndPaint();
		break;
	}
	case WM_MOUSEMOVE: {
		MOUSE_MOVE->CallBack();
		break;
	}
//	case WM_LBUTTONDOWN: {
//		MOUSE_LDOWN->CallBack();
//		break;
//	}
//	case WM_LBUTTONUP: {
//		MOUSE_LUP->CallBack();
//		break;
//	}
//	case WM_RBUTTONDOWN: {
//		MOUSE_RDOWN->CallBack();
//		break;
//	}
//	case WM_RBUTTONUP: {
//		MOUSE_RUP->CallBack();
//		break;
//	}
	case WM_LBUTTONDBLCLK: {
		MOUSE_LDCLICK->CallBack();
		break;
	}
	case WM_RBUTTONDBLCLK: {
		MOUSE_RDCLICK->CallBack();
		break;
	}
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	default: {
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	}
	return 0;
}

void Scratch::Log(std::string str) {
	log.append(printTime());
	log.append(str);
	log.push_back('\n');
}

int Scratch::AppMain(int argc, char **argv) {
	getLogfileName();
	Log("Initializing program.");
	Log("Checking arguments.");
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--test"))
			argu.test = true;
		else if (strcmp(argv[i], "--console"))
			argu.console = true;
		else if (strcmp(argv[i], "-printPluginName"))
			argu.printPluginName = true;
		else if (strcmp(argv[i], "-printPluginVersion"))
			argu.printPluginVersion = true;
	}
	Log("Searching plugins.");
	InstallExtension();
	Log(toString(ext.size()) + "plugins has been searched");
	Log("Initializing instance.");
	ProgramInstance = GetModuleHandle(NULL);
	ConsoleHandle = Console::GetConsoleHanle();
	Log("Register window class");
	RegisterWindowClass();
	Log("Creating the main window.");
	CreateMainWindow();
	Log("Pre initialisate plugins.");
	for (auto &c : ext) {
		Log("\tPlugin Loaded: " + c->extid);
		c->preInitialisation();
	}
	Log("Pre initialisate plugins.");
	for (auto &c : ext)
		c->preInitialisation();
	Log("Pre initialisate plugins.");
	for (auto &c : ext)
		c->preInitialisation();
	Log("Running message loop.");
	ShowMainWindow();
	int result = MessageLoop(0);
	Log("Program has been finished.");
	AppRelease();
	return result;
}

void Scratch::AppRelease() {
	_rmdir("./temp/");
	Log("Temp file has been deleted.");
	if (_access("./log", 00) == -1)
		_mkdir("./log");
	std::string f = getLogfileName();
	std::ofstream ofs(f, std::ios::out);
	ofs.write(log.c_str(), log.size());
	ofs.flush();
	ofs.close();
}

void Scratch::InstallExtension() {
	ext.clear();
	FileIO fio;
	fio.LoadExtension(ext);
}

Scratch::Scratch() {
	sc.ClassName = L"Z-Editor";
	sc.WindowTitle = L"Z-Editor";
}

Scratch::~Scratch() {

}
