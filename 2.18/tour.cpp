// tour.cpp 费用流
#include <queue>
#include <cstring>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("tour.in");
std::ofstream out("tour.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 100010, Maxm = 200010;
int head[Maxn], ver[Maxm << 1], flow[Maxm << 1], cost[Maxm << 1], Next[Maxm << 1], tot;
int s, t, p[Maxn], d[Maxn], mv[Maxn];
bool v[Maxn];

inline void add(int u, int v, int t, int w);
bool spfa();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n, m, ans = 0;
    in >> n >> m;
    s = n + 1, t = n + 2;
    for (int i = 1; i <= n; i++)
        in >> mv[i];
    for (int i = 1; i <= n; i++)
        add(s, i, 0x3f3f3f3f, 0), add(i, t, mv[i], 0);
    for (int i = 1, x; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            in >> x;
            if (x != -1)
                add(i, j, 0x3f3f3f3f, x);
        }
    while (spfa()) {
        int pre, dlt = 0x3f3f3f3f;
        for (int i = t; i != s; i = ver[pre ^ 1])
            pre = p[i], dlt = std::min(dlt, flow[pre]);
        for (int i = t; i != s; i = ver[pre ^ 1])
            pre = p[i], flow[pre] -= dlt, flow[pre ^ 1] += dlt;
        ans += d[t] * dlt;
    }
    out << ans << '\n';
    return 0;
}

inline void add(int u, int v, int t, int w) {
    ver[++tot] = v, flow[tot] = t, cost[tot] = w, Next[tot] = head[u], head[u] = tot;
    ver[++tot] = u, flow[tot] = 0, cost[tot] = -w, Next[tot] = head[v], head[v] = tot;
}

bool spfa() {
    std::queue<int> q;
    memset(v, false, sizeof v);
    memset(p, false, sizeof p);
    memset(d, 0x3f, sizeof(d));
    d[s] = 0, v[s] = true;
    q.push(s);
    while (q.size()) {
        int x = q.front(); q.pop();
		v[x] = false;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = cost[i];
			if (d[y] > d[x] + z && flow[i]) {
				d[y] = d[x] + z;
                p[y] = i;
                if (!v[y])
                    q.push(y), v[y] = true;
			}
		}
    }
    return d[t] < 0x3f3f3f3f;
}