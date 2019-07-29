// garden.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

#define debug

#ifndef debug

std::ifstream in("garden.in");
std::ofstream out("garden.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m, x2, y2, x, y;
int a[100005];

inline int dist(int x, int y, int x2);
int search(int x);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n;
	for (int i = 1; i <= n; i++)
		in >> a[i];
	std::sort(a + 1, a + n + 1);
	in >> m;
	while (m--) {
		in >> x2 >> y2 >> x >> y;
		if ((y2 > 0 && y > 0) || (y2 < 0 && y < 0))
			out << (std::abs(x2 - x) + std::abs(y2 - y)) << '\n';
		else {
			int k = search(x2), ans = 0x7fffffff;
			if (k >= 1)
				ans = std::min(ans, dist(x2, y2, a[k]) + dist(x, y, a[k]));
			if (k < n)
				ans = std::min(ans, dist(x2, y2, a[k + 1]) + dist(x, y, a[k + 1]));
			out << ans << '\n';
		}
	}
	return 0;
}

inline int dist(int x, int y, int x2) {
	return std::abs(x - x2) + std::abs(y);
}

int search(int x) {
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l - 1;
}
