// 1353.cpp
#include <iostream>

template <typename T>
inline T max(const T a, const T b) { return a > b ? a : b;}

int main(int argc, const char * argv[]) {
	char a[205], b[205], c;
	int f[205][205] = {0}, m = 0, n = 0;
	while ((c = std::cin.get()) != '\n')
		a[++m] = c;
	while ((c = std::cin.get()) != '\n')
		b[++n] = c;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] == b[j])
				f[i][j] = max(f[i - 1][j], max(f[i][j - 1], f[i - 1][j - 1] + 1));
			else
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
	std::cout << f[m][n] << std::endl;
	return 0;
}
