#include "../CompileOption.h"
#ifdef ZSCRATCH_COMPILE_WIN32
#include "../MainWindow.h"
#include <Windows.h>


MainWindow::MainWindow() {}


MainWindow::~MainWindow() {}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
}

int MainWindow::CreateMainWindow(int argc, char **argv) {
	HINSTANCE ProgramInstance = GetModuleHandle(NULL);
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
	wcex.lpszClassName = WindowTitle;
	if (RegisterClassExW(&wcex) == FALSE)
		return 0x0100;
	WindowHandle = CreateWindowEx(0, WindowTitle, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, NULL, 0);
	if (!WindowHandle)
		return 0x0101;
	ShowWindow(WindowHandle, SW_NORMAL);
	UpdateWindow(WindowHandle);
	SendMessage(WindowHandle, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	return 0x0000;
}

int MainWindow::EntryMainLoop() {
	MSG msg = { 0 };
	while (GetMessageW(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return msg.wParam;
}

#endif
