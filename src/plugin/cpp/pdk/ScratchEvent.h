#pragma once
#ifndef SCRATCH_EVENT
#define SCRATCH_EVENT
#include <functional>
#include <vector>
#include "IScratchEvent.h"
class PDK ScratchEvent: public IScratchEvent {
public:
	ScratchEvent();
	~ScratchEvent();
	virtual int CallBack();
	friend int CallBack(ScratchEvent e);
};

#endif
