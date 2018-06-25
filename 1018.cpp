// 1018.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int n, x, y;
	std::cin >> n >> x >> y;
	std::cout << int(n - y / (double)x) << std::endl;
	return 0;
}
