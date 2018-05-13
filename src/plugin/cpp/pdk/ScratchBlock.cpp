#include "ScratchBlock.h"
#include "ScratchBlockItem.h"

std::vector<IScratchBlockItem*> ScratchBlock::compileBlock() {
	bool fmt = false;
	std::string tmp;
	std::vector<IScratchBlockItem*> ret;
	for (size_t i = 0; i < title.size(); i++) {
		if (fmt) {
			if (title[i] == '%')
				tmp.push_back(title[i]);
			else {
				IScratchBlockItem *p = new ScratchBlockItem();
				p->type = ItemType::TextLabel;
				ret.push_back(p);
				switch (title[i]) {
				case 'b':
					break;
				case 'r':
					break;
				case 'c':
					break;
				case 'm':
					break;
				}
			}
			fmt = false;
		}
		else if (title[i] == '%') {
			fmt = true;
		}
		else
			tmp.push_back(title[i]);
	}
	return std::vector<IScratchBlockItem*>();
}

ScratchBlock::ScratchBlock() {}


ScratchBlock::~ScratchBlock() {}
