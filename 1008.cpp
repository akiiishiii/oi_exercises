#include <iostream>

int main(int argc, const char * argv[]) {
	int a;
	std::cin >> a;
	while (a) {
		std::cout << a % 10;
		a /= 10;
	}
	std::cout << std::endl;
	return 0;
}
