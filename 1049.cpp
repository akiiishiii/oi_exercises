// 1049.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int m, n;
	std::cin >> m >> n;
	if (!(m % 2))
		m++;
	if (!(n % 2))
		n--;
	if (m > n) {
		std::cout << "0\n";
		return 0;
	}
	std::cout << (m + n) * (n - m - (n - m - 1) / 2) / 2 << std::endl;
	return 0;
}
