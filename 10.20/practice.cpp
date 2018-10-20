// practice.cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("practice.in");
std::ofstream out("practice.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const SIZE = 50001;
int f[SIZE][20], head[SIZE], ver[SIZE << 1], Next[SIZE << 1], a[SIZE], d[SIZE];
int n, m, tot, t, ans = 0x3f3f3f3f;
std::queue<int> q;

inline void add(int u, int v) { ver[++tot] = v, Next[tot] = head[u], head[u] = tot; }
inline void bfs();
inline int lca(int x, int y);
inline int dist(int x, int y) { return (x == y) ? 0 : (d[x] + d[y] - 2 * d[::lca(x, y)]); }
inline void read(int &x);
inline void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    ::read(n);
    t = int(log2(n)) + 1;
    for (int i = 1, x, y; i < n; i++) {
        ::read(x);
        ::read(y);
        ::add(x, y);
        ::add(y, x);
    }
    for (int i = 1; i <= n; i++)
        in >> a[i];
    ::bfs();
    for (int i = 1; i < n; i++)
        for (int j = i + 1, temp; j <= n; j++) {
            temp = 0;
            for (int k = 1; k <= n; k++)
                temp += std::min(::dist(k, i), ::dist(k, j)) * a[k];
            ans = std::min(ans, temp);
        }
    out << ans << '\n';
    return 0;
}

inline void bfs() {
	q.push(1); d[1] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (d[y]) continue;
			d[y] = d[x] + 1;
			f[y][0] = x;
			for (int j = 1; j <= t; j++)
				f[y][j] = f[f[y][j - 1]][j - 1];
			q.push(y);
		}
	}
}

inline int lca(int x, int y) {
	if (d[x] > d[y]) std::swap(x, y);
	for (int i = t; i >= 0; i--)
		if (d[f[y][i]] >= d[x]) y = f[y][i];
	if (x == y) return x;
	for (int i = t; i >= 0; i--)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

inline void read(int &x) {
    x = 0;
    char c = in.get();
    while (c < '0' || c > '9')
        c = in.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = in.get();
    }
}

inline void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        out.put(x / y + 48);
        x %= y;
    }
}