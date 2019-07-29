// tree.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

//#define debug

#ifndef debug

std::ifstream in("tree.in");
std::ofstream out("tree.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n;
long long ans = 0;
int prt[100005], son[100005] = {0};

struct edge {
	int x, y, z;
	edge() {}
	edge(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
	bool operator<(edge const &e) const { return z < e.z; }
} a[100005];

int search(int x) { return x == prt[x] ? x : x = search(prt[x]); }

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n;
	for (int i = 1, s, t, d; i < n; i++)
		in >> s >> t >> d, a[i] = edge(s, t, d), ans += d;
	std::sort(a + 1, a + n);
	for (int i = 1; i <= n; i++)
		prt[i] = i, son[i] = 1;
	for (int i = 1; i < n; i++) {
		int f1 = search(a[i].x), f2 = search(a[i].y);
		ans += (long long)(a[i].z + 1) * ((long long)son[f1] * son[f2] - 1);
		prt[f2] = f1, son[f1] += son[f2];
	}
	out << ans << '\n';
	return 0;
}
