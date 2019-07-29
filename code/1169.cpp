// 1169.cpp
#include <iostream>
#include <iomanip>

int a[1000001], b[1000001], n;
double ansxor, ansand, ansor;

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	for (int k = 0; k < 31; k++) {
		int last[2] = {0, 0}, c1 = 0, c2 = 0;
		for (int i = 1; i <= n; i++) {
			b[i] = ((a[i] >> k) & 1);
			if (b[i]) {
				ansxor += (1 << k) * 1.0 / n / n;
				ansand += (1 << k) * 1.0 / n / n;
				ansor += (1 << k) * 1.0 / n / n;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (b[i]) {
				ansand += (1 << k) * 2.0 / n / n * (i - 1 - last[0]);
				ansor += (1 << k) * 2.0 / n / n * (i - 1);
			} else
				ansor += (1 << k) * 2.0 / n / n * last[1];
			ansxor += (1 << k) * 2.0 / n / n * (b[i] ? c1 : c2);
			c1++;
			if (b[i])
				std::swap(c1, c2);
			last[b[i]] = i;
		}
	}
	std::cout << std::fixed << std::setprecision(3) << ansxor << ' ' << ansand << ' ' << ansor << '\n';
	return 0;
}
