/** String.h - ZScratch
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

/**
* String.h
* Alex Cui, April 2018
*
* 
*/

#pragma once
#include <string>
#include <sstream>
std::wstring StringToWString(const std::string &str);
std::string WStringToString(const std::wstring &wstr);
template<typename T>
std::string toString(T v) {
	std::stringstream strm;
	std::string ret;
	strm << v;
	strm >> ret;
	strm.str("");
	return ret;
}
