// 1023.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int a, b, c;
	std::cin >> a >> b >> c;
	if (a + b > c && a + c > b && b + c > a)
		std::cout << "yes\n";
	else
		std::cout << "no\n";
	return 0;
}
