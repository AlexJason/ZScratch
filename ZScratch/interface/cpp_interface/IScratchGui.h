#pragma once
#ifndef PDK_SCRATCHGUI
#define PDK_SCRATCHGUI
#include <functional>
#include "ScratchGuiStruct.h"
class PDK IScratchGui {
protected:
	void virtual unused() = 0;
public:
	std::function<void(ScratchGuiStruct)> onPaint;
};

void PDK RegisterObject(IScratchGui *pGui);
IScratchGui PDK *CreateGuiObject(double _PDK_VERSION);

namespace pdk {
	/*
	 * void pdk::DrawRectangle
	 * HDC hdc				: The DC handle of the window.
	 * int x0, int y0		: The top-left point of the rectangle.
	 * int x1, int y1		: The bottom-right point of the rectangle.
	 * COLORREF fill		: The rectangle filling color.
	 * COLORREF frame		: The rectangle frame color.
	*/
	void PDK DrawRectangle(HDC hdc, int x0, int y0, int x1, int y1, COLORREF fill);
	void PDK DrawRectangle(HDC hdc, int x0, int y0, int x1, int y1, COLORREF fill, COLORREF frame);

	/*
	 * void pdk::FillText
	 * HDC hdc				: The DC handle of the window.
	 * int x0, int y0		: The top-left point of the rectangle.
	 * int width				: The width of text label, if auto, please set it as 0.
	 * int height			: The width of text label, if auto, please set it as 0.
	 * char* text			: The text you want to show.
	 * COLORREF font			: The font color.
	 * COLORREF bg			: The background color.
	*/
	void PDK FillText(HDC hdc, int x0, int y0, int width, int height, char *text, size_t size, COLORREF font, unsigned int FORMAT = 0);
	void PDK FillText(HDC hdc, int x0, int y0, int width, int height, std::string text, COLORREF font, unsigned int FORMAT = 0);
	void PDK FillText(HDC hdc, int x0, int y0, int width, int height, char *text, size_t size, COLORREF font, COLORREF bg, unsigned int FORMAT = 0);
	void PDK FillText(HDC hdc, int x0, int y0, int width, int height, std::string text, COLORREF font, COLORREF bg, unsigned int FORMAT = 0);

	/*
	 * void pdk::SetRect	: set the rect.
	*/
	void PDK SetRect(RECT *rc, int x0, int y0, int x1, int y1);
}

#endif
