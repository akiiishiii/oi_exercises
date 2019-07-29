// 1377.cpp
#include <iostream>
#include <bitset>
#include <queue>

int const Maxn = 30001;
int Next[Maxn], ver[Maxn], head[Maxn], deg[Maxn], a[Maxn];
std::bitset<Maxn> b[Maxn];
int m, n, tot, cnt, debugid;

inline void add(int x, int y);
void topsort();

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <=n; i++)
		b[i].set(i);
	for (int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		add(x, y);
		b[x].set(y);
	}
	topsort();
	for (int i = cnt; i > 0; i--)
		for (int j = head[a[i]]; j; j=Next[j])
			b[a[i]] |= b[ver[j]];
	for (int i = 1; i <= n; i++)
		std::cout << b[i].count() << '\n';
	return 0;
}

inline void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
	deg[y]++;
}

void topsort() {
	std::queue<int> q;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0)
			q.push(i);
	while (q.size()) {
		int x = q.front(); q.pop();
		a[++cnt] = x;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (--deg[y] == 0)
				q.push(y);
		}
	}
}
