// 1020.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int n;
	std::cin >> n;
	if (n == 1 || n == 3 || n == 5)
		std::cout << "NO\n";
	else
		std::cout << "YES\n";
		return 0;
}
