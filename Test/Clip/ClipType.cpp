/**
*	Copyright(C) 2017-2018 Alex Cui
*
*	This program is free software : you can redistribute it and/or modify
*	it under the terms of the GNU Affero General Public License as
*	published by the Free Software Foundation, either version 3 of the
*	License, or (at your option) any later version.
*
*	This program is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
*	GNU Affero General Public License for more details.
*
*	You should have received a copy of the GNU Affero General Public License
*	along with this program.If not, see <https://www.gnu.org/licenses/>.
*/

#include "ClipType.h"

#include <map>
#include <string>
#include <utility>

const std::map<ClipType, unsigned int> ClipTypeLength = {
	std::pair<ClipType, unsigned int>(ClipType::Cbyte, sizeof(char)),
	std::pair<ClipType, unsigned int>(ClipType::Cbool, sizeof(bool)),
	std::pair<ClipType, unsigned int>(ClipType::Cchar, sizeof(char)),
	std::pair<ClipType, unsigned int>(ClipType::Cfloat, sizeof(double)),
	std::pair<ClipType, unsigned int>(ClipType::Cint, sizeof(long long)),
	std::pair<ClipType, unsigned int>(ClipType::Cpointer, sizeof(int*)),
	std::pair<ClipType, unsigned int>(ClipType::Cstring, sizeof(std::string)),
};

unsigned int CLIPAPI GetOriginalTypeLength(ClipType t) {
	return ClipTypeLength.at(t);
}
