#include <iostream>

int main(int argc, const char * argv[]) {
	int n;
	std::cin >> n;
	for (char c = 'A'; c <= 'A' + n - 1; c++) {
		for (int i = 0; i < n - (c - 'A') - 1; i++)
			std::cout.put(' ');
		for (char c1 = 'A'; c1 < c; c1++)
			std::cout.put(c1);
		std::cout.put(c);
		for (char c1 = c - 1; c1 >= 'A'; c1--)
			std::cout.put(c1);
		std::cout.put('\n');
	}
	return 0;
}
