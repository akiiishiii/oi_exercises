#include <iostream>

int main(int argc, const char * argv[]) {
	int s;
	std::cin >> s;
	std::cout << (s > 100 ? "Bike\n" : s == 100 ? "All\n" : "Walk\n");
	return 0;
}
