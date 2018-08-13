// 1353.cpp
#include <iostream>
#include <cstring>

template <typename T>
inline T max(const T &a, const T &b) { return a > b ? a : b; }

int main(int argc, const char * argv[]) {
	char a[205], b[205], c;
	int f[205][205], m = 0, n = 0;
	memset(f, 0, sizeof(f));
	while ((c = std::cin.get()) != '\n')
		a[++m] = c;
	while ((c = std::cin.get()) != '\n')
		b[++n] = c;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] == b[j])
				f[i][j] = max(max(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1] + 1);
			else
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
	std::cout << f[m][n] << std::endl;
	return 0;
}
