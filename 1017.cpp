#include <iostream>

int main(int argc, const char * argv[]) {
	int a, b;
	std::cin >> a >> b;
	std::cout << (int)(a >= 10 || b >= 20) << std::endl;
	return 0;
}
