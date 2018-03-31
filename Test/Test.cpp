#include "Clip\Clip.h"
#include "Clip\ClipRuntime.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#pragma comment(lib, "Clip/Clip.lib")

using namespace std;

int main() {
	ifstream file("1.clp", ios::in);
	std::vector<std::vector<std::string>> t;
	if (file.is_open())
		t = GetWordList(file);
	else
		cout << "ERR";
	for (auto c : t) {
		for (auto c2 : c)
			cout << c2 << endl;
		cout << "==========" << endl;
	}
	Run(t);
	getchar();
	return 0;
}

