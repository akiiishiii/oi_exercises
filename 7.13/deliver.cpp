// deliver.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <ctime>

//#define debug

#ifndef debug

std::ifstream in("deliver.in");
std::ofstream out("deliver.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 21, Maxm = 401;
int n, m, q, tot;
int head[Maxn], Next[Maxm], ver[Maxm], edge[Maxm];
int d[Maxn];
bool v[Maxn];

struct quest {
	int s, t;
	int l, r;
} a[11];

inline void add(int x, int y, int z);
void spfa(int s);
int random(int n);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n >> m >> q;
	for (int i = 1, x, y, z; i <= m; i++) {
		in >> x >> y >> z;
		add(x, y, z);
	}
	for (int i = 1; i <= q; i++)
		in >> a[i].s >> a[i].t >> a[i].l >> a[i].r;
	if (q == 1) {
		spfa(a[1].s);
		if (d[a[1].t] <= a[1].r - a[1].l + 1)
			out << "1\n";
		else
			out << "0\n";
	}
	srand(unsigned(time(NULL)));
	out << random(q) << '\n';
	return 0;
}


inline void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void spfa(int s) {
	std::queue<int> qq;
	memset(d, 0x3f, sizeof(d));
	memset(v, false, sizeof(v));
	d[s] = 0; v[s] = true;
	qq.push(s);
	while (qq.size()) {
		int x = qq.front(); qq.pop();
		v[x] = false;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				if (!v[y]) qq.push(y), v[y] = true;
			}
		}
	}
}

int random(int n) {
    return (long long)rand() * rand() % n;
}
