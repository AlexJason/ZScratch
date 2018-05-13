/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	Error.h
 * @author	Alex Cui
 * @date	May, 2018
 * @details	Define errors.
*/

#pragma once
#ifndef ZSCRATCH_UTIL_ERROR
#define ZSCRATCH_UTIL_ERROR

#include <string>

#define ERROR(x, n) \
	class x { \
	public: \
		std::string str; \
		bool exit; \
		x() = default; \
		x(std::string t, bool b) { this->str = t; this->exit = b; } \
		operator void() {} \
		operator int() { return n; } \
	};

#define DEFINE_ERROR(x) ERROR(x, 1)

#endif
