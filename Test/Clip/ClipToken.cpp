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
					strln.push_back(temp);
					temp.clear();
				}
				inString = !inString;
			}
			if (inString) {
				if (strin[i] == '\\') {
					temp.push_back(GetAsciiChar(strin[++i]));
					continue;
				}
				temp.push_back(strin[i]);
				continue;
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

char CLIPAPI GetAsciiChar(char c)
{
	return 0;
}
