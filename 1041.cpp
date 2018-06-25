// 1041.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int n, sum = 0;
	std::cin >> n;
	while (n) {
		sum += (n % 10);
		n /= 10;
	}
	std::cout << sum << std::endl;
	return 0;
}
