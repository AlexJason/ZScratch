#pragma once
#include "IScratchBlock.h"
class ScratchBlock :public IScratchBlock {
public:

	virtual std::vector<IScratchBlockItem*> compileBlock();

	ScratchBlock();
	~ScratchBlock();
};

