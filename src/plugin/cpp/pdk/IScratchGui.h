#pragma once
#ifndef PDK_SCRATCHGUI
#define PDK_SCRATCHGUI
#include <functional>
#include "ScratchGuiStruct.h"
class PDK IScratchGui {
protected:
	void virtual unused() = 0;
public:
	std::function<void(ScratchGuiStruct*)> onPaint;
};

void PDK RegisterObject(IScratchGui *pGui);
IScratchGui PDK *CreateGuiObject(double _PDK_VERSION);

#include "IColor.h"
#include "IRect.h"
namespace pdk {
	void PDK DrawRectangle(IRect rc, IColor fill);
	void PDK DrawRectangle(IRect rc, IColor fill, IColor frame);

	void PDK FillText(IRect rc, char *text, size_t size, IColor font, unsigned int FORMAT = 0);
	void PDK FillText(IRect rc, char *text, size_t size, IColor font, IColor bg, unsigned int FORMAT = 0);
	void PDK FillText(IRect rc, std::string text, IColor font, unsigned int FORMAT = 0);
	void PDK FillText(IRect rc, std::string text, IColor font, IColor bg, unsigned int FORMAT = 0);
}

#endif
