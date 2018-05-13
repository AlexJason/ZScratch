#pragma once
#include "pdk.h"
#include <functional>
#include <vector>
#ifndef PDK_SCRATCHEVENT
#define PDK_SCRATCHEVENT
class PDK IScratchEvent {
protected:
	std::vector<std::function<int(void*)>> callback;
public:
	virtual int CallBack() = 0;
	IScratchEvent();
	~IScratchEvent();
	int RegisterEventCallback(std::function<int(void*)> callback);
};

typedef IScratchEvent *pIScratchEvent;

extern pIScratchEvent PDK MOUSE_MOVE, MOUSE_LDOWN, MOUSE_RDOWN, MOUSE_LUP, MOUSE_RUP, MOUSE_LDCLICK, MOUSE_RDCLICK, MOUSE_SHEEL;
extern pIScratchEvent PDK KEYBOARD_PRESS;
extern pIScratchEvent PDK RUNTIME_ENTRY, RUNTIME_KILL;
extern pIScratchEvent PDK APP_ONLOAD, APP_DESTROY;
extern pIScratchEvent PDK EXT_LOAD, EXT_KILL;
#endif
