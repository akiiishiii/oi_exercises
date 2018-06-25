// 1035.cpp
#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
	int n, age, tot = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> age;
		tot += age;
	}
	std::cout << std::fixed << std::setprecision(2) << (double)tot / n << std::endl;
	return 0;
}
