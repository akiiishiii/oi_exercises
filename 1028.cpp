#include <iostream>

int main(int argc, const char * argv[]) {
	int a;
	std::cin >> a;
	if (a >= 86)
		std::cout << "VERY GOOD\n";
	else if (a >=60)
		std::cout << "GOOD\n";
	else
		std::cout << "BAD\n";
	return 0;
}
