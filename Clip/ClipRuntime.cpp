#include "ClipRuntime.h"
#include "ClipStatement.h"

std::vector<std::tuple<std::string, std::string>> define;
std::vector<std::tuple<std::string, std::string, unsigned int, unsigned int>> function;
std::vector<std::tuple<std::string, std::string>> variables;

int CLIPAPI Run(std::vector<std::vector<std::string>> codes) {
	unsigned long line = 0;
	for (auto exp : codes) {
		try {
			if (exp[0] == "#") {
				if (exp[1] == "define") {
					while (exp.size() < 3)
						exp.push_back("");
					define.push_back(std::make_tuple(exp[2], exp[3]));
				}
			}
			else if (exp[0] == "function") {
				for (size_t i = line; i < codes.size(); i++) {
					static unsigned long level = 1;
					for (auto c : codes[i]) {
						if (c == "{") {
							level++;
						}
						else if (c == "}") {
							level--;
							if (level == 0) {
								function.push_back(std::make_tuple(exp[1], exp[2], line, i));
							}
						}
					}
				}
			}
			else if (exp[0] == "var") {
				variables.push_back(std::make_tuple(exp[1], exp[2]));
			}
		}
		catch(int) {

		}
		++line;
	}
	return 0;
}
