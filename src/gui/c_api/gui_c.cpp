/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	gui_c.cpp
 * @author	Alex Cui
 * @date	July, 2018
 * @details	C API for gui.h
*/

#include "gui_c.h"
#include "../gui.h"
#include "../class.h"

void Application_FromArg(Handle *obj, int argc, char **argv) {
	(*obj) = new Application(argc, argv);
}
void Point_FromInt(Handle *obj, int x, int y) {
	(*obj) = new Point(x, y);
}
void Rect_FromPoint(Handle *obj, Handle p0, Handle p1) {
	Point *lt = static_cast<Point*>(p0);
	Point *rb = static_cast<Point*>(p1);
	(*obj) = new Rect(*lt, *rb);
}
void Rect_FromPos(Handle *obj, int x0, int y0, int x1, int y1) {
	(*obj) = new Rect(Point(x0, y0), Point(x1, y1));
}
void Window_FromRect(Handle *obj, Handle rc) {
	Rect *prc = static_cast<Rect*>(rc);
	(*obj) = new Window(*prc);
}
void Window_SetWindowShowMode(Handle *obj, ShowMode sm) {
	static_cast<Window*>(*obj)->SetWindowShowMode(static_cast<WindowShowMode>(sm));
}
