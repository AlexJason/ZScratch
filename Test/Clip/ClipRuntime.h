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
#ifndef CLIP_RUNTIME
#define CLIP_RUNTIME
#include "ClipDefine.h"
#include <vector>
#include <string>
#include <map>
#include <tuple>
extern std::vector<std::tuple<std::string, std::string>> define;
extern std::vector<std::tuple<std::string, std::string, unsigned int, unsigned int>> function;
extern std::vector<std::tuple<std::string, std::string>> variables;

int CLIPAPI Run(std::vector<std::vector<std::string>> codes);
#endif
