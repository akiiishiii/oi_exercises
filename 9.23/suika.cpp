// suika.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <deque>
#include <cmath>

//#define debug

#ifndef debug

std::ifstream in("suika.in");
std::ofstream out("suika.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

struct status {
	int x;
	bool col;
};
const int N = 5005, M = 30005;
int head[N], ver[M], edge[M], Next[M], d[N][2], w[N], s[N];
int n, m, tot;
std::deque<status> q;
bool v[N][2], color[N];

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void spfa();
int dist(int u, int v, bool c);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n >> m;
	for (int i = 1; i <= n; i++)
		in >> color[i];
	for (int i = 1; i <= n; i++)
		in >> w[i];
	for (int i = 1; i <= n; i++)
		in >> s[i];
	for (int i = 1, u, v, k; i <= m; i++) {
		in >> u >> v >> k;
		add(u, v, k);
	}
	spfa();
	out << std::min(d[n][0], d[n][1]) << '\n';
	return 0;
}

void spfa() {
	memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    q.push_back((status){1, 0});
    v[1][0] = true;
    d[1][0] = 0;
    q.push_back((status){5001, 0});
    while(q.size()) {
        status now = q.front();
        q.pop_front();
        int x = now.x;
        v[x][now.col] = false;
        for(int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y][now.col ^ 1] > d[x][now.col] + std::max(z + dist(x, y, now.col), 0)) {
                d[y][now.col ^ 1] = d[x][now.col] + std::max(z + dist(x, y, now.col), 0);
                if (v[y][now.col ^ 1])
                    continue;
                if (d[y][now.col ^ 1] <= d[q.front().x][q.front().col])
                    q.push_front((status){y, now.col ^ 1});
                else
                    q.push_back((status){y, now.col ^ 1});
                v[y][now.col ^ 1] = true;
            }
        }
        if (d[x][now.col ^ 1] > d[x][now.col] + (s[x] * (color[x] ^ now.col))) {
            d[x][now.col ^ 1] = d[x][now.col] + (s[x] * (color[x] ^ now.col));
            if (v[x][now.col ^ 1])
                continue;
            if (d[x][now.col ^ 1] <= d[q.front().x][q.front().col])
                q.push_front((status){x, now.col ^ 1});
            else
                q.push_back((status){x, now.col ^ 1});
            v[x][now.col ^ 1] = true;
        }
    }
}

int dist(int u, int v, bool c) {
    int uc = color[u] ^ c, vc = color[v] ^ c, dv = abs(w[u] - w[v]);
    if (uc == vc)
        return 0;
    if (uc && !vc)
        return dv;
    if (!uc && vc)
        return -dv;
}
