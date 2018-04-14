#pragma once
#ifndef SCRATCH_ORIGINAL
#define SCRATCH_ORIGINAL
#include "..\ZScratch\interface\cpp_interface\pdk.h"
#pragma comment(lib, "cpp_interface.lib")
class EXPORT Plugin final :public IScratchExtension {
	void construct() override {
		this->extid = "scratch-gui";
		this->title = "Scratch Gui";
	}
	virtual void preInitialisation() {
		IScratchGui *pGui;
		if (nullptr == (pGui = CreateGuiObject(PLUGIN_SDK_VER)))
			return;
		pGui->onPaint = [](ScratchGuiStruct gui) {
			RECT rc = gui.rc;
			HBRUSH hbr = CreateSolidBrush(0xffffff);
			FillRect(gui.hdc, &rc, hbr);
			FrameRect(gui.hdc, &rc, hbr);
			DeleteObject(hbr);
			hbr = CreateSolidBrush(0x848484);
			rc.bottom = rc.top + 25;
			FillRect(gui.hdc, &rc, hbr);
			FrameRect(gui.hdc, &rc, hbr);
			DeleteObject(hbr);
			hbr = CreateSolidBrush(0xcccccc);
			rc.top = rc.bottom + 10;
			rc.bottom = rc.top + 25;
			rc.left += 10;
			rc.right = rc.left + 483;
			FrameRect(gui.hdc, &rc, hbr);
			DeleteObject(hbr);
		};
		RegisterObject(pGui);
	}
	virtual void Initialisation() {}
	virtual void postInitialisation() {}
};
#endif
