#include <iostream>

int main(int argc, const char * argv[]) {
	int n;
	std::cin >> n;
	for (int i = 2; i * i <= n; i++)
		if (!(n % i)) {
			std::cout << "NO\n";
			return 0;
		}
	std::cout << "YES\n";
	return 0;
}
