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
#include "ClipToken.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

std::vector<std::vector<std::string>> CLIPAPI GetWordList(std::ifstream &f) {
	std::vector<std::vector<std::string>> ret(0);
	std::vector<std::string> strln(0);
	std::string strin;
	std::smatch match;
	while (!f.eof()) {
		std::getline(f, strin);
		if (strin.size() == 0)
			continue;
		bool beg, end;
		while (!((beg = std::regex_match(strin, match, std::regex("\\S+[\\s\\S]*"))) & \
			(end = std::regex_match(strin, match, std::regex("[\\s\\S]*\\S+"))))) {
			if (!beg) {
				std::regex_search(strin, match, std::regex("\\S+[\\s\\S]*"));
				strin = match.str();
			}
			if (!end) {
				std::regex_search(strin, match, std::regex("[\\s\\S]*\\S+"));
				strin = match.str();
			}
		}
		bool inString = false;
		std::string temp;
		for (size_t i = 0; i < strin.size(); i++) {
			if (strin[i] == '\"') {
				if (inString) {
					temp.push_back('\"');
					strln.push_back(temp);
					temp.clear();
				}
				inString = !inString;
				continue;
			}
			if (inString) {
				if (strin[i] == '\\') {
					temp.push_back(GetAsciiChar(strin[++i]));
					continue;
				}
				temp.push_back(strin[i]);
				continue;
			}
			if (strin[i] == '/') {
				if (strin[i + 1] == '/') {
					i = strin.size();
					continue;
				}
			}
			std::string tstr = strin.substr(i);
			if (std::regex_search(tstr, match, std::regex("[_a-zA-Z]+[_a-zA-Z0-9]*")) && \
				match[0].str()[0] == tstr[0]) {
				strln.push_back(match[0].str());
				i += match[0].str().size() - 1;
				continue;
			}
			std::string t2(1, strin[i]);
			if (!std::regex_match(t2, match, std::regex("\\s"))) {
				strln.push_back(t2);
				continue;
			}
		}
		ret.push_back(strln);
		strln.clear();
	}
	return ret;
}

char CLIPAPI GetAsciiChar(char c) {

	return 0;
}
