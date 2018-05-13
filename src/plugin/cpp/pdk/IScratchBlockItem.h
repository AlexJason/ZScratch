#pragma once
#ifndef PDK_SCRATCHBLOCKITEM
#define PDK_SCRATCHBLOCKITEM
#include <string>
enum class ItemType { TextLabel, CircleInput, RectInput, BoolInput };
class IScratchBlockItem {
public:
	ItemType type;
	std::string value;

	IScratchBlockItem();
	~IScratchBlockItem();
};
#endif
