/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	IScratchChooseBox.cpp
 * @author	Alex Cui
 * @date	April, 2018
 * @details	Class of Choose box for blocks.
*/

#include "IScratchChooseBox.h"


NAMESPACE_
IScratchChooseBox::IScratchChooseBox() {
}


IScratchChooseBox::~IScratchChooseBox() {
}

size_t IScratchChooseBox::size() {
	return this->item.size();
}

void IScratchChooseBox::add(std::string item) {
	if (!isExist(item))
		this->item.push_back(item);
}

size_t IScratchChooseBox::isExist(std::string item) {
	for (size_t i = 0; i < this->item.size(); i++)
		if (this->item[i] == item)
			return i;
	return 0;
}

void IScratchChooseBox::del(std::string item) {
	size_t index = 0;
	if (index = isExist(item))
		this->item.erase(this->item.begin() + index);
}

void RegisterObject(IScratchChooseBox *obj) {

}
_NAMESPACE
