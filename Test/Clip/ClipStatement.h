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
#ifndef CLIP_STATEMENT
#define CLIP_STATEMENT

#include "ClipDefine.h"

#include <functional>
#include <vector>

class prebuild_statement {
public:

};

class ifdef_prebuild :public prebuild_statement {
public:
	std::string define;
	std::function<void()> body;
};

class ifndef_prebuild :public ifdef_prebuild, public prebuild_statement {
public:
};

class define_prebuild :public prebuild_statement {
public:
	std::string define;
};

class statement {
public:

};

template<typename T>
class exp1_statement :public statement {
public:
	std::function<T()> des;
};

template<typename T>
class exp2_statement :public statement {
public:
	std::function<T()> des;
	std::function<T()> src;
};

class if_statement :public statement {
public:
	std::function<bool()> exp;
	std::function<void()> ifpart;
};

class if_else_statement :public if_statement, public statement {
public:
	std::function<void()> elsepart;
};

class for_statement :public statement {
public:
	std::function<void()> exp1;
	std::function<void()> exp2;
	std::function<void()> exp3;
	std::function<void()> body;
};

class while_statement :public statement {
public:
	std::function<void()> exp;
	std::function<void()> body;
};

class dowhile_statement :public while_statement, public statement {
public:
};

#endif
