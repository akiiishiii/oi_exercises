// magic.cpp
#include <fstream>
#include <iostream>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("magic.in");
std::ofstream out("magic.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

struct edge {
	int x,y,z;
	bool operator<(edge const &e) const;
} es[150];

int n, m, a[17], prt[17], sum[1<<17], cost[1<<17], f[1<<17];

int search(int x);
int kruskal(int s);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	int tot;
	in >> n >> m;
	for (int i = 0; i < n; i++)
		in >> a[i];
	for (int i = 1; i <= m; i++)
		in >> es[i].x >> es[i].y >> es[i].z;
	std::sort(es + 1, es + m + 1);
	tot = (1 << n) - 1;
	for (int i = 0; i <= tot; i++)
		for (int j = 0; j < n; j++)
			if ((i >> j) & 1)
				sum[i] += a[j];
	for (int i = 0; i <= tot; i++)
		if (!sum[i])
			cost[i] = kruskal(i);
		else
			cost[i] = 0x3f3f3f3f;
	for (int i = 1; i <= tot; i++)
		f[i] = 0x3f3f3f3f;
	f[0] = 0;
	for (int i = 0; i <= tot; i++) {
		if (sum[i])
			continue;
		for (int j = 1; j <= tot; j++) {
			if (sum[j])
				continue;
			f[i | j] = std::min(f[i | j], f[i] + cost[j]);
		}
	}
	if (f[tot] == 0x3f3f3f3f)
		out << "Impossible\n";
	else
		out << f[tot] << '\n';
	return 0;
}

bool edge::operator<(edge const &e) const {
	return z < e.z;
}

int search(int x) {
	return ((x != prt[x]) ? (prt[x] = search(prt[x])) : x);
}

int kruskal(int s) {
	int min_cost = 0, cnt = 0, tot = 0, fx, fy;
	for (int i = 0; i < n; i++) {
		prt[i] = i;
		if ((s >> i) & 1)
			tot++;
	}
	for (int i = 1; i <= m; i++)
		if (((s >> es[i].x) & 1) && ((s >> es[i].y) & 1)) {
			fx = search(es[i].x);
			fy = search(es[i].y);
			if (fx != fy) {
				prt[fx] = fy;
				cnt++;
				min_cost += es[i].z;
			}
		}
	if (cnt + 1 != tot) 
	 	return 0x3f3f3f3f;
	else
		return min_cost;
}
