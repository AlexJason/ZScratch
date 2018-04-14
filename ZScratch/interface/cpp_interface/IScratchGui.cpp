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
