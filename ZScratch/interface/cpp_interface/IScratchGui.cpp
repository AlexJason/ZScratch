#include "pdk.h"

#include "ScratchGui.h"

#include "RegisterInfo.h"

std::vector<IScratchGui*> PDK RegScratchGui;

void RegisterObject(IScratchGui * pGui) {
	RegScratchGui.push_back(pGui);
}

IScratchGui * CreateGuiObject(double _PDK_VERSION) {
	if ((int)_PDK_VERSION == (int)PLUGIN_SDK_VER) {
		return new ScratchGui;
	}
	return nullptr;
}

namespace pdk {
	void PDK DrawRectangle(HDC hdc, int x0, int y0, int x1, int y1, COLORREF fill) {
		HBRUSH hbr = CreateSolidBrush(fill);
		RECT rc = { x0, y0, x1, y1 };
		FillRect(hdc, &rc, hbr);
		FrameRect(hdc, &rc, hbr);
		DeleteObject(hbr);
	}

	void PDK DrawRectangle(HDC hdc, int x0, int y0, int x1, int y1, COLORREF fill, COLORREF frame) {
		HBRUSH hbr = CreateSolidBrush(fill);
		RECT rc = { x0, y0, x1, y1 };
		FillRect(hdc, &rc, hbr);
		DeleteObject(hbr);
		hbr = CreateSolidBrush(frame);
		FrameRect(hdc, &rc, hbr);
		DeleteObject(hbr);
	}

	void PDK FillText(HDC hdc, int x0, int y0, int width, int height, char *text, size_t size, COLORREF font, unsigned int FORMAT) {
		RECT rc = { x0, y0, x0 + width, y0 + height };
		DrawTextA(hdc, text, size, &rc, FORMAT);
	}

	void PDK FillText(HDC hdc, int x0, int y0, int width, int height, std::string text, COLORREF font, unsigned int FORMAT) {
		RECT rc = { x0, y0, x0 + width, y0 + height };
		DrawTextA(hdc, text.c_str(), text.size(), &rc, FORMAT);
	}

	void PDK FillText(HDC hdc, int x0, int y0, int width, int height, char *text, size_t size, COLORREF font, COLORREF bg, unsigned int FORMAT);
	
	void PDK FillText(HDC hdc, int x0, int y0, int width, int height, std::string text, COLORREF font, COLORREF bg, unsigned int FORMAT);

	void PDK SetRect(RECT * rc, int x0, int y0, int x1, int y1) {
		rc->left = x0;
		rc->right = x1;
		rc->top = y0;
		rc->bottom = y1;
	}
}
