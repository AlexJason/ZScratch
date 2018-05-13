#include "ScratchEvent.h"

pIScratchEvent PDK MOUSE_MOVE = new ScratchEvent(), \
	MOUSE_LDOWN = new ScratchEvent(), MOUSE_RDOWN = new ScratchEvent(), \
	MOUSE_LUP = new ScratchEvent(), MOUSE_RUP = new ScratchEvent(), \
	MOUSE_LDCLICK = new ScratchEvent(), MOUSE_RDCLICK = new ScratchEvent(), \
	MOUSE_SHEEL = new ScratchEvent();
pIScratchEvent PDK KEYBOARD_PRESS = new ScratchEvent();
pIScratchEvent PDK RUNTIME_ENTRY = new ScratchEvent(), RUNTIME_KILL = new ScratchEvent();
pIScratchEvent PDK APP_ONLOAD = new ScratchEvent(), APP_DESTROY = new ScratchEvent();
pIScratchEvent PDK EXT_LOAD = new ScratchEvent(), EXT_KILL = new ScratchEvent();

ScratchEvent::ScratchEvent() {}


ScratchEvent::~ScratchEvent() {}

int ScratchEvent::CallBack() {
	for (auto c : callback)
		c(nullptr);
	return callback.size();
}

int CallBack(ScratchEvent e) {
	return e.CallBack();
}
