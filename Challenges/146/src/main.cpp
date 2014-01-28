#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

// Polygon perimeter

int main(int argc, char* argv[])
{
	int num; float r;
	cin >> num >> r;

	double p = 2 * num * r * sin(M_PI / num);

	cout.precision(3);
	cout << fixed << p << endl;
	return 0;
}
