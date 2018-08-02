/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	ZScratch.cpp
 * @author	Alex Cui
 * @date	May, 2018
 * @details	This is the entry function of the program.
*/

#include "ZScratch.h"

#include "gui\gui.h"
#include "scratch\Scratch.h"
#include "util\String.h"
#include "util\Time.h"

int main(int argc, char **argv) {
	//Pre config
	const std::string title = "ZScratch";

	//Qt application instance
	Application *app = new Application(argc, argv);//QApplication

	//Program instance
	Scratch *sc = new Scratch();
	int result = 0;
	sc->Log("Initializing program.");

	//Qt window form
	Window *mainWnd = new Window(Rect(Point(0, 0), Point(100, 100)));
	mainWnd->Show();

	//Main application
	sc->AppMain(argc, argv);
	result = app->exec();

	//Memory release
	delete sc, mainWnd, app;

	return result;
}
