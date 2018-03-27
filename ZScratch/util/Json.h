/** Json.h - ZScratch
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
* Json.h
* Alex Cui, March 2018
*
* The class of the read and write to json file with jsoncpp.
*/

#pragma once
#ifndef UTIL_JSON
#define UTIL_JSON
#include <string>
#include <fstream>
class Json {
public:
	std::fstream file;
public:
	template<typename T>
	T ReadValue(std::string key, T defaultValue = T());
	template<typename T>
	void WriteValue(std::string key, T value);
public:
	Json();
	~Json();
};
#endif

