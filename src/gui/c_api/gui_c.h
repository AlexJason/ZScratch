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

#ifndef _In
#define _In
#endif
#ifndef _Out
#define _Out
#endif
#ifndef _In_Out
#define _In_Out
#endif

	typedef void *Handle;
	enum ShowMode { SW_NORMAL, SW_MAX, SW_MIN, SW_FULLSCREEN };

	void CDLL Application_FromArg(_Out Handle *obj, _In int argc, _In char **argv);
	void CDLL Application_Exec(_Out Handle *obj);
	void CDLL Point_FromInt(_Out Handle *obj, _In int x, _In int y);
	void CDLL Point_SetXFromInt(_In_Out Handle *obj, _In int x);
	void CDLL Point_SetYFromInt(_In_Out Handle *obj, _In int y);
	void CDLL Point_GetXAsInt(_In Handle obj, _Out int *x);
	void CDLL Point_GetYAsInt(_In Handle obj, _Out int *y);
	void CDLL Rect_FromPoint(_Out Handle *obj, _In Handle p0, _In Handle p1);
	void CDLL Rect_FromPos(_Out Handle *obj, _In int x0, _In int y0, _In int x1, _In int y1);
	void CDLL Rect_SetLeftTopFromPoint(_In_Out Handle *obj, _In Handle p);
	void CDLL Rect_SetRightBottomFromPoint(_In_Out Handle *obj, _In Handle p);
	void CDLL Rect_GetLeftTopAsPoint(_In Handle obj, _Out Handle *p);
	void CDLL Rect_GetRightBottomAsPoint(_In Handle obj, _Out Handle *p);
	void CDLL Window_FromRect(_Out Handle *obj, _In Handle rc);
	void CDLL Window_SetRectFromRect(_Out Handle *obj, _In Handle rc);
	void CDLL Window_GetRectAsRect(_In Handle obj, _Out Handle *rc);
	void CDLL Window_SetWindowShowMode(_In_Out Handle *obj, _In ShowMode sm);
	void CDLL Window_GetWindowShowMode(_In Handle obj, _Out ShowMode *sm);
	void CDLL Window_Show(_In_Out Handle *obj);
	void CDLL Window_ShowFullScreen(_In_Out Handle *obj);
	void CDLL Window_ShowMaximum(_In_Out Handle *obj);
	void CDLL Window_ShowMinimum(_In_Out Handle *obj);
	void CDLL Widget_FromRect(_Out Handle *obj, _In_Out Handle *parent, _In Handle rc);
	void CDLL Widget_SetRectFromRect(_In Handle obj, _In Handle rc);
	void CDLL Widget_GetRectAsRect(_In Handle obj, _Out Handle rc);
	void CDLL Widget_Show(_In_Out Handle *obj);

#ifdef __cplusplus
}
#endif

#endif
