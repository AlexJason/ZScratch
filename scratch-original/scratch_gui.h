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
		pGui->onPaint = [this](ScratchGuiStruct gui) { this->GuiOnPaint(gui); };
		RegisterObject(pGui);
		IScratchValue *v;
		InitObject(v);
	}

	virtual void Initialisation() {
		MOUSE_LUP->RegisterEventCallback([](void* x)->int { return 0; });
	}

	virtual void postInitialisation() {}

	void GuiOnPaint(ScratchGuiStruct gui) {
		RECT rc = gui.rc;
		pdk::SetRect(&rc, rc.left, rc.top, rc.right, rc.top + 40);
		pdk::DrawRectangle(gui.hdc, rc.left, rc.top, rc.right, rc.bottom, 0x848484);
		pdk::SetRect(&rc, rc.left + 10, rc.bottom + 10, rc.left + 483, rc.top + 40);
		pdk::DrawRectangle(gui.hdc, rc.left, rc.top, rc.right, rc.bottom, 0x848484);
	}
};
#endif
