#pragma once
#ifndef PDK_SCRATCHGUISTRUCT
#define PDK_SCRATCHGUISTRUCT
#include <Windows.h>
struct ScratchGuiStruct {
	RECT rc;
	HWND hwnd;
	HDC hdc;
};
#endif
