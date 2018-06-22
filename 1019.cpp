#include <iostream>

int main(int argc, const char * argv[]) {
	int a, b;
	std::cin >> a >> b;
	std::cout << (int)((a >= 60 && b < 60) || (a < 60) && (b >= 60)) << std::endl;
}
