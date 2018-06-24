#include <iostream>

int main(int argc, const char * argv[]) {
	int m, a[16][16];
	std::cin >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			std::cin >> a[i][j];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++)
			std::cout << a[j][i] << ' ';
		std::cout << std::endl;
	}
	return 0;
}
