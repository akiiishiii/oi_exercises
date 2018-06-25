// 1043.cpp
#include <iostream>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a;}

int main(int argc, const char * argv[]) {
	int a, b;
	std::cin >> a >> b;
	std::cout << gcd(a, b) << std::endl;
	return 0;
}
