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

#pragma once
#ifndef CLIP_TYPE
#define CLIP_TYPE

#include <map>
#include <string>
#include <utility>

static const std::map<std::string, int> ClipTypeLength = {
	std::pair<std::string, int>("byte", sizeof(char)),
	std::pair<std::string, int>("bool", sizeof(bool)),
	std::pair<std::string, int>("char", sizeof(char)),
	std::pair<std::string, int>("float", sizeof(double)),
	std::pair<std::string, int>("int", sizeof(long long)),
	std::pair<std::string, int>("pointer", sizeof(int*)),
	std::pair<std::string, int>("string", sizeof(std::string)),
};


#endif
