// 1325.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

inline double f(double x) { return pow(x, 5) - 15 * pow(x, 4) + 85 * pow(x, 3) - 225 * pow(x, 2) + 274 * x - 121;}
double binary_search(double(*fun) (double), double l, double r);

int main (int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(6) << binary_search(f, 1.5, 2.4) << std::endl;
	return 0;
}

double binary_search(double(*fun) (double), double l, double r) {
	double mid = fun((l + r) / 2);
	if (fabs(fun(l) - fun(r)) <= 0.0000001)
		return l;
	else if (mid > 0)
		return binary_search(fun, (l + r) / 2, r);
	else if (mid < 0)
		return binary_search(fun, l, (l + r) / 2);
	return 0;
}
