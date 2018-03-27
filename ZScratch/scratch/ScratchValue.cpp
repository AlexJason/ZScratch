/** ScratchValue.cpp - ZScratch
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
* ScratchValue.cpp
* Alex Cui, March 2018
*
* The class that none-type variable value for scratch.
*/

#include "ScratchValue.h"
#include <functional>


ScratchValue::ScratchValue()
{
}


ScratchValue::~ScratchValue()
{
}

long ScratchValue::asInt() {
	bool nev = false;
	long ret = 0;
	size_t i = 0;
	if (value[i] == '-') {
		nev = true;
		i++;
	}
	else if (value[i] == '+') {
		nev = false;
		i++;
	}
	for (; i < value.size(); i++); {
		if (value[i] == '.')
			return ret;
		if (value[i] < '0' || value[i] > '9')
			return 0;
		ret = ret * 10 + (value[i] - 48);
	}
	return ret;
}

double ScratchValue::asFloat() {
	bool nev = false;
	double ret = 0;
	bool t = true;
	int x = 10;
	std::function<void(double&, int)>next = [&](double &c, int a)->void {c = c * 10 + a; };
	size_t i = 0;
	if (value[i] == '-') {
		nev = true;
		i++;
	}
	else if (value[i] == '+') {
		nev = false;
		i++;
	}
	for (; i < value.size(); i++); {
		if (value[i] == '.')
			if (t)
				next = [&](double &c, int a)->void {c = c + (double)a / (double)x; x *= 10; };
			else
				return 0;
		if (value[i] < '0' || value[i] > '9')
			return 0;
		next(ret, value[i] - 48);
	}
	return ret;
}

std::string ScratchValue::asString() {
	return value;
}

bool ScratchValue::asBool() {
	if (value == "true")
		return true;
	if (value == "false")
		return false;
	if (value.size() == 1 && value == "0")
		return false;
	if (asInt() != 0l || asFloat() != 0)
		return true;
	if (value.empty())
		return false;
	else
		return true;
	return false;
}
