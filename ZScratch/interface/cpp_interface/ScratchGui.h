#pragma once
#ifndef SCRATCH_GUI
#define SCRATCH_GUI
#include "pdk.h"
#include "IScratchGui.h"
#include <vector>
class PDK ScratchGui :public IScratchGui {
protected:
	virtual void unused() {}
public:
	ScratchGui();
	~ScratchGui();
};
#endif
