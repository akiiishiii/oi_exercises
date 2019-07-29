// patrol.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("patrol.in");
std::ofstream out("patrol.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, k, tot;
int d[100005], pre[100005], f[100005], v[100005], x, y, z, p;
int Next[200005], edge[200005], ver[200005], head[100005];
std::queue<int> q;

inline void add(int x, int y);
int bfs(int s);
int get();
void reversed();
void dp(int x);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n >> k;
	tot = 1;
	for (int i = 1, a, b; i < n; i++) {
		in >> a >> b;
		add(a, b), add(b, a);
	}
	x = get(), y = 0, z = 1;
	if(k == 2)
		reversed(), dp(1), z = 2;
	out << 2 * (n - 1) - x - y + z << '\n';
	return 0;
}

inline void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], edge[tot] = 1, head[x] = tot;
}

int bfs(int s) {
	int x, y;
	memset(d, 0x3f, sizeof(d));
	q.push(s);
	d[s] = pre[s] = 0;
	while (q.size()) {
		x = q.front();
		q.pop();
		for (int i = head[x]; i; i = Next[i])
			if (d[ver[i]] == 0x3f3f3f3f)
				d[ver[i]] = d[x] + edge[i], pre[ver[i]] = i, q.push(ver[i]);
	}
	for (x = y = 1; x <= n; x++)
		if(d[x] > d[y])
			y = x;
	return y;
}

int get() {
	p = bfs(bfs(1));
	return d[p];
}

void reversed() {
	for (; pre[p]; p = ver[pre[p] ^ 1])
		edge[pre[p]] = edge[pre[p] ^ 1] = -1;
}

void dp(int x) {
	v[x] = 1;
	for (int i = head[x]; i; i = Next[i])
		if (!v[ver[i]]) {
			dp(ver[i]);
			y = std::max(y, f[ver[i]] + f[x] + edge[i]);
			f[x] = std::max(f[x], f[ver[i]] + edge[i]);
		}
}
