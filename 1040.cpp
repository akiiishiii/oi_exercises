// 1040.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int n, sum = 0, factor[1600], m = 0;
	std::cin >> n;
	for (int i = 1; i * i <= n; i++)
		if (!(n % i)) {
			factor[++m] = i;
			if (i != n / i)
				factor[++m] = n / i;
		}
	for (int i = 1; i <= m; i++)
		sum += factor[i];
	std::cout << sum << std::endl;
	return 0;
}
