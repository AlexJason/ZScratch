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

#include <iostream>

void Application_FromArg(_Out Handle *obj, _In int argc, _In char **argv) {
	(*obj) = new Application(argc, argv);
}
void Application_Exec(_Out Handle *obj) {
	static_cast<Application*>(*obj)->exec();
}
void Point_FromInt(_Out Handle *obj, _In int x, _In int y) {
	(*obj) = new Point(x, y);
}
void Point_SetXFromInt(_In_Out Handle *obj, _In int x) {
	static_cast<Point*>(*obj)->x = x;
}
void Point_SetYFromInt(_In_Out Handle *obj, _In int y) {
	static_cast<Point*>(*obj)->y = y;
}
void Point_GetXAsInt(_In Handle obj, _Out int *x) {
	*x = static_cast<Point*>(obj)->x;
}
void Point_GetYAsInt(_In Handle obj, _Out int *y) {
	*y = static_cast<Point*>(obj)->y;
}
void Rect_FromPoint(_Out Handle *obj, _In Handle p0, _In Handle p1) {
	Point *lt = static_cast<Point*>(p0);
	Point *rb = static_cast<Point*>(p1);
	(*obj) = new Rect(*lt, *rb);
}
void Rect_FromPos(_Out Handle *obj, _In int x0, _In int y0, _In int x1, _In int y1) {
	(*obj) = new Rect(Point(x0, y0), Point(x1, y1));
}
void Window_FromRect(_Out Handle *obj, _In Handle rc) {
	Rect *prc = static_cast<Rect*>(rc);
	(*obj) = new Window(*prc);
}
void Window_SetWindowShowMode(_In_Out Handle *obj, _In ShowMode sm) {
	static_cast<Window*>(*obj)->SetWindowShowMode(static_cast<WindowShowMode>(sm));
}
void Window_Show(_In_Out Handle *obj) {
	static_cast<Window*>(*obj)->Show();
}
