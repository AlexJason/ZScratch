#pragma once
#ifndef PDK_SCRATCHBLOCK
#define PDK_SCRATCHBLOCK
#include <string>
#include <vector>

#include "IScratchBlockItem.h"
class IScratchBlock {
public:
	std::string title;

	//Temps:
	std::vector<IScratchBlockItem*> compiled;
	bool hasCompiled;
public:
	virtual std::vector<IScratchBlockItem*> compileBlock() = 0;

	IScratchBlock();
	~IScratchBlock();
};
#endif
