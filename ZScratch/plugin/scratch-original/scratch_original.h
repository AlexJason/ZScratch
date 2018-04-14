#pragma once
#ifndef SCRATCH_ORIGINAL
#define SCRATCH_ORIGINAL
#include "..\..\interface\cpp\IScratchExtension.h"
#include "..\..\interface\cpp\IScratchGui.h"
class scratch_original final :public IScratchExtension {
	void construct() override {
		this->extid = "scratch-original";
		this->title = "Original Scratch";
	}
	virtual void preInitialisation() {
		IScratchGui *app;
		app->registerObject();
	}
	virtual void Initialisation() {}
	virtual void postInitialisation() {}
};
#endif
