// 4468.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

int const Maxn = 10000005;

struct query {
	int x, y, e;
	bool operator<(query const &q) const { return e > q.e; }
} a[Maxn];

int T, n, tot;
int tmp[Maxn], prt[Maxn];
bool flag = true;

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		tot = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i].x >> a[i].y >> a[i].e;
			tmp[++tot] = a[i].x;
			tmp[++tot] = a[i].y;
		}
		std::sort(a + 1, a + n + 1);
		std::sort(tmp + 1, tmp + 1 + tot);
		tot = std::unique(tmp + 1, tmp + tot + 1) - (tmp + 1);
		for (int i = 1; i <= tot; i++)
			prt[i] = i;
		for (int i = 1; i <= n; i++) {
			a[i].x = std::lower_bound(tmp + 1, tmp + tot + 1, a[i].x) - tmp;
			a[i].y = std::lower_bound(tmp + 1, tmp + tot + 1, a[i].y) - tmp;
			if (a[i].e)
				prt[search(a[i].x)] = search(a[i].y);
			else if (search(a[i].x) == search(a[i].y)) {
				flag = false;
				break;
			}
		}
		std::cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;
}
