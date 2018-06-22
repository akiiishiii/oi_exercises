#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
	const double PI = 3.1415926;
	int r;
	std::cin >> r;
	std::cout << std::fixed << std::setprecision(2) << 2 * PI * r << ' ' << PI * r * r << std::endl;
	return 0;
}
