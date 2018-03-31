/*#include "Clip\Clip.h"
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
	for (auto c : t)
		for (auto c2 : c)
			cout << c2 << endl;
	getchar();
	return 0;
}
*/

#include <stdio.h>
int main() {
	int x, y = 0xcccccccc;
	(x = y) = 12 / 4;
	printf("%d %d", x, y);
	getchar();
	return 0;
}
