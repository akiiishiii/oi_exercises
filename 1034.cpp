#include <iostream>

int main(int argc, const char * argv[]) {
	int n;
	long long ans = 1;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		ans *= i;
	std::cout << ans << std::endl;
	return 0;
}
