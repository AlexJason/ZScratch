#pragma once
#ifndef SCRATCH_VARIABLE
#define SCRATCH_VARIABLE
#include <string>
#include "ScratchValue.h"
class ScratchVariable {
public:
	std::string name;
	ScratchValue value;
public:
	ScratchVariable();
	~ScratchVariable();

};
#endif
