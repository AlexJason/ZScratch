#pragma once
#ifndef GUI_WIN32_MAINWINDOW
#define GUI_WIN32_MAINWINDOW
#include "Type.h"
#include <string>
class MainWindow {
public:
	MainWindow();
	~MainWindow();

	Application AppHandle;
	Window WindowHandle;
	String WindowTitle;

	int CreateMainWindow(int argc, char **argv);
	int EntryMainLoop();
};
#endif
