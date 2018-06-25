// 1022.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int w;
	char c;
	std::cin >> w >> c;
	std::cout << ((w > 1000) ? (w % 500 ? ((w - 1000) / 500 + 1) : ((w - 1000) / 500)) * 4 + 8 : 8) + (c == 'y' ? 5 : 0) << std::endl;
	return 0;
}
