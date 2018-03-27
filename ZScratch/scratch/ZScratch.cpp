/** ZScratch.cpp - ZScratch
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
* ZScratch.cpp
* Alex Cui, March 2018
*
* This is the main class of the program.
*/

#include "ZScratch.h"
#include "..\gui\Paint.h"

LPCWSTR ZScratch::ClassName = L"ClipCC-ZE";
LPCWSTR ZScratch::WindowTitle = L"Z-Editor";
HWND ZScratch::WindowHandle = nullptr;
HWND ZScratch::ConsoleHandle = nullptr;
HINSTANCE ZScratch::ProgramInstance = nullptr;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return ZScratch::WndProc(hwnd, msg, wParam, lParam);
}

ATOM ZScratch::RegisterWindowClass() {
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

BOOL ZScratch::CreateMainWindow() {
	HWND WindowHandle = CreateWindowEx(0, ClassName, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, NULL, 0);
	if (!WindowHandle)
		return FALSE;
	ShowWindow(WindowHandle, SW_NORMAL);
	UpdateWindow(WindowHandle);
	SendMessage(WindowHandle, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	return TRUE;
}

WPARAM ZScratch::MessageLoop() {
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

WPARAM ZScratch::MessageLoop(int) {
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT ZScratch::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CREATE: {
		break;
	}
	case WM_PAINT: {
		Paint::BeginPaint(hwnd);
		HBRUSH hbr;
		hbr = CreateSolidBrush(0xffffff);

		Paint::EndPaint();
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

ZScratch::ZScratch() {

}


ZScratch::~ZScratch() {

}
