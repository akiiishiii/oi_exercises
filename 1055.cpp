// 1055.cpp
#include <iostream>

long long jc(int n);

int main(int argc, const char * argv[]) {
	int n;
	long long ans = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		ans += jc(i);
	std::cout << ans << std::endl;
	return 0;
}

long long jc(int n) {
	long long ans = 1;
	for (int i = n; i >= 1; i--) {
		ans *= i;
	}
	return ans;
}
