/**	Translate.cpp - ZScratch
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
* Translate.cpp
* Alex Cui, March 2018
*
* This is the class for translator of the program.
*/

#include "Translate.h"
#include <utility>

Translate::Translate() {
}


Translate::~Translate() {
}

void Translate::AddTranslation(std::string str, std::string lang, std::string trans) {
	Strings[str][lang] = trans;
}

std::string Translate::GetTranslation(std::string str, std::string lang) {
	auto v1 = Strings.find(str);
	if (v1 != Strings.end()) {
		auto v2 = v1->second.find(lang);
		if (v2 != v1->second.end())
			return v2->second;
	}
	return nullptr;
}
