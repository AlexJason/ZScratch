/**
* This file is part of ZScratch.
* ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
* ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
*
* @file	gui_c.h
* @author	Alex Cui
* @date	July, 2018
* @details	C API for gui.h
*/
#pragma once
#ifndef C_GUI_H_
#define C_GUI_H_
#ifdef _DLL
#define CDLL _declspec(dllexport)
#else
#define CDLL _declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

	typedef void *Handle;
	enum ShowMode { SW_NORMAL, SW_MAX, SW_MIN, SW_FULLSCREEN };

	void CDLL Application_FromArg(Handle *obj, int argc, char **argv);
	void CDLL Point_FromInt(Handle *obj, int x, int y);
	void CDLL Rect_FromPoint(Handle *obj, Handle p0, Handle p1);
	void CDLL Rect_FromPos(Handle *obj, int x0, int y0, int x1, int y1);
	void CDLL Window_FromRect(Handle *obj, Handle rc);
	void CDLL Window_SetWindowShowMode(Handle *obj, ShowMode sm);

#ifdef __cplusplus
}
#endif

#endif
