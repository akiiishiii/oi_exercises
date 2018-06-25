// 1021.cpp
#include <iostream>

template <typename T>
inline T max(T a, T b) { return a > b ? a : b;}

int main(int argc, const char * argv[]) {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << max(a, max(b, c)) << std::endl;
}
