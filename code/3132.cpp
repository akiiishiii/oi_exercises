// 3132.cpp
#include <iostream>

int n, m, maxx = 1, prt[100001], d[100001];

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]);} 

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		prt[i] = i, d[i] = 1;
	for (int i = 1, k, x, y; i <= m; i++) {
		std::cin >> k;
		if (k & 1) {
			std::cin >> x >> y;
			int p1 = search(x), p2 = search(y);
			if (p1 != p2) {
				prt[p2] = p1;
				d[p1] = d[p2] = d[p1] + d[p2];
				maxx = std::max(d[p2], maxx);
			}
		} else
			std::cout << maxx << '\n';
	}
	return 0;
}
