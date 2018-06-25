#include <iostream>
#include <vector>

const int U = 0, D = 1, C = 2;

template <typename T>
inline T min(T a, T b) { return a < b ? a : b;}

int main(int argc, const char * argv[]) {
	int costs[200005][3];
	int n, u = 0, d = 0, c = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> costs[i][U] >> costs[i][D] >> costs[i][C];
	}
	for (int i = 0; i < n; i++) {
		int nu = min(d, c) + costs[i][U];
		int nd = min(u, c) + costs[i][D];
		int nc = min(u, d) + costs[i][C];
		u = nu;
		d = nd;
		c = nc;
	}
	std::cout << min(u, min(d, c)) << std::endl;
	return 0;
}
