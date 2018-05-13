/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	IScratchBlock.cpp
 * @author	Alex Cui
 * @date	April, 2018
 * @details	Class of Blocks.
*/

#include "IScratchBlock.h"
NAMESPACE_
std::vector<IScratchBlockItem*> IScratchBlock::compileBlock() {
	bool fmt = false;
	std::string tmp;
	std::vector<IScratchBlockItem*> ret;
	for (size_t i = 0; i < title.size(); i++) {
		if (fmt) {
			if (title[i] == '%')
				tmp.push_back(title[i]);
			else {
				IScratchBlockItem *p = new IScratchBlockItem();
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
_NAMESPACE
