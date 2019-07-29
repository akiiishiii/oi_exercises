// group.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

//#define debug

#ifndef debug

std::ifstream in("group.in");
std::ofstream out("group.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m, q, p;

int head[n], Next[m],

struct edge {
	int x, y, z;
	bool operator>(edge const &e) const { return z > e.z; }
};

int search(int x) {
	return (prt[x] == x) ? x : (prt[x] = search(prt[x]));
}

void kruskal() {
	int f1, f2, k = 0;
	for (int i = 1; i <= n; i++)
		prt[i] = i;
	for (int i = 1; i <= m; i++) {
		f1 = search(a[i].x);
		f2 = search(a[i].y);
		if (f1 != f2) {
			ans += a[i].z;
			prt[f1] = f2;
			if (++k == n - 1)
				break;
		}
	}
}

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n >> m >> q >> p;
	ans = 0;
	for(int i = 1; i <= m; i++)
		std::cin >> a[i].x >> a[i].y >> a[i].z;
	std::sort(a + 1, a + m + 1, std::greater<edge>());
	kruskal();
    dfs(1);
    st();
    for (int i = 1; i <= q; i++) {
        
    }
	return 0;
}
