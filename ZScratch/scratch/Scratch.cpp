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
#include "..\gui\Paint.h"
#include "..\util\FileIO.h"
#include "..\util\Console.h"
#include "..\util\AppArgu.h"

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
	HWND WindowHandle = CreateWindowEx(0, ClassName, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, NULL, 0);
	if (!WindowHandle)
		return FALSE;
	ShowWindow(WindowHandle, SW_NORMAL);
	UpdateWindow(WindowHandle);
	SendMessage(WindowHandle, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	return TRUE;
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
		p.EndPaint();
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

int Scratch::AppMain(int argc, char **argv) {
	/*for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--test"))
			argu.test = true;
		else if (strcmp(argv[i], "--console"))
			argu.console = true;
		else if (strcmp(argv[i], "-printPluginName"))
			argu.printPluginName = true;
		else if (strcmp(argv[i], "-printPluginVersion"))
			argu.printPluginVersion = true;
	}*/
	InstallExtension();
	ProgramInstance = GetModuleHandle(NULL);
	ConsoleHandle = Console::GetConsoleHanle();
	RegisterWindowClass();
	CreateMainWindow();
	int result;
	result = MessageLoop(0);
	//Sleep(1000);
	return 0;
}

void Scratch::InstallExtension() {
	//ext.clear();
	FileIO fio;
	//fio.LoadExtension(ext);
}

Scratch::Scratch() {
	sc.ClassName	= L"Z-Editor";
	sc.WindowTitle	= L"Z-Editor";
}

Scratch::~Scratch() {

}
