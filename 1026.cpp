#include <iostream>

int main(int argc, const char * argv[]) {
	char c1, c2;
	std::cin >> c1 >> c2;
	if (c1 == 'S') {
		if (c2 == 'R')
			std::cout << "Fail\n";
		else if (c2 == 'S')
			std::cout << "Equ\n";
		else if (c2 == 'P')
			std::cout << "Win\n";
	} else if (c1 == 'R') {
		if (c2 == 'P')
			std::cout << "Fail\n";
		else if (c2 == 'R')
			std::cout << "Equ\n";
		else if (c2 == 'S')
			std::cout << "Win\n";
	} else if (c1 == 'P') {
		if (c2 == 'S')
			std::cout << "Fail\n";
		else if (c2 == 'P')
			std::cout << "Equ\n";
		else if (c2 == 'R')
			std::cout << "Win\n";
	}
	return 0;
}
