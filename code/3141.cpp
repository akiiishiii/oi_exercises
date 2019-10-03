// 3141.cpp
#include <iostream>
#include <cstring>

long long n, m, k;
long long f[205][205], d[20005];
int v[20005];

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m >> k;
	for (int i = 1, x; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			std::cin >> x;
			d[x]= i + j - 1;
		}
	for (int i = 1; i <= n * m; i++)
		if (!v[d[i]]) {
			v[d[i]] = true;
			memset(f, 0, sizeof(f));
			f[0][0] = 1;
			for (int i = 0; i <= n + m - 2; i++)
				for (int j = 0; j <= i; j++)
					if (f[i][j]) {
						if (v[i + 1] != -1) {
							f[i + 1][j + 1] += f[i][j];
							if (f[i + 1][j + 1] < 0 || f[i][j] == -1)
								f[i + 1][j + 1] = -1;
						}
						if (v[i + 1] != 1 && j) {
							f[i + 1][j - 1] += f[i][j];
							if (f[i + 1][j - 1] < 0 || f[i][j] == -1)
								f[i + 1][j - 1] = -1;
						}
					}
			if (f[n + m - 1][0] >= k || f[n + m - 1][0] == -1)
				continue;
			v[d[i]] = -1;
			k -= f[n + m - 1][0];
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			std::cout << ((v[i + j - 1] == 1) ? '(' : ')');
		std::cout << '\n';
	}
	return 0;
}
