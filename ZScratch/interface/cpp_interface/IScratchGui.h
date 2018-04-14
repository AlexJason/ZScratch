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

#endif
