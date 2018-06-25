// 1004.cpp
#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
	long long a, b;
	std::cin >> a >> b;
	std::cout << std::fixed << std::setprecision(3) << b * 100 / double(a) << "%\n";
	return 0;
}
