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

#include <iostream>
#include <cmath>
using namespace std;
class Point {
private:
	double x, y;
public:
	void set(double xx, double yy);
	double getX();
	double getY();
	double Distance(Point &p);
};

void Point::set(double xx, double yy) {
	x = xx;
	y = yy;
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

double Point::Distance(Point &p) {
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}
double Distance(Point &p1, Point &p2) {
	return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}

int main() {
	Point p1, p2;
	double x, y;
	cout << "点A的x, y坐标: ";
	cin >> x >> y;
	p1.set(x, y);
	cout << "点B的x, y坐标: ";
	cin >> x >> y;
	p2.set(x, y);
	cout << "(全局函数)距离为: " << Distance(p1, p2) << endl;
	cout << "(成员函数)距离为: " << p1.Distance(p2) << endl;
	system("pause");
	return 0;
}

