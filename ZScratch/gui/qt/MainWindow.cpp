#include "../MainWindow.h"
#include "qwindow.h"

int MainWindow::CreateMainWindow(int argc, char **argv) {
	this->AppHandle = new QApplication(argc, argv);
	this->WindowHandle = new QWindow();
	this->WindowHandle.setTitle(this->WindowTitle);
	return 0;
}

int MainWindow::EntryMainLoop() {
	return AppHandle.exec();
}

