// 1054.cpp
#include <iostream>

int v[10001] = {0}, prime[10001];

int main(int argc, const char * argv[]) {
	int m, n, p, q = 0;
	std::cin >> m >> n;
	p = n;
	for (int i = 2; i <= p; i++) {
		if (!v[i]) {
			v[i] = i;
			prime[++q] = i;
		}
		for (int j = 1; j <= q; j++) {
			if (prime[j] > v[i] || prime[j] > p / i)
				break;
			v[i * prime[j]] = prime[j];
		}
	}
	for (int i = 0; i <= q; i++)
		if (prime[i] >= m && prime[i] <= n)
			std::cout << prime[i] << ' ';
	std::cout << '\n';
	return 0;
}
