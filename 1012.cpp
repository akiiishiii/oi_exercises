// 1012.cpp
#include <iostream>
#include <cmath>
#include <iomanip>

int main(int argc, const char * argv[]) {
	double xa, ya, xb, yb;
	std::cin >> xa >> ya >> xb >> yb;
	std::cout << std::fixed << std::setprecision(3) << sqrt(pow(xa - xb, 2) + pow(ya - yb, 2)) << std::endl;
	return 0;
}
