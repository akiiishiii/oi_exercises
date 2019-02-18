// tree.cpp 最大流最小割
#include <queue>
#include <cstring>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("tree.in");
std::ofstream out("tree.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 20010, Maxm = 200010;
int head[Maxn], ver[Maxm << 1], flow[Maxm << 1], Next[Maxm << 1], tot;
int u[Maxm], v[Maxm], w[Maxm];
int d[Maxm << 1];
int s, t, l;

inline void add(int u, int v, int t);
bool bfs();
int dfs(int x, int maxf);
int dinic();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n, m, ans = 0;
    in >> n >> m;
    for (int i = 1; i <= m; i++)
        in >> u[i] >> v[i] >> w[i];
    in >> s >> t >> l;
    memset(head, 0, sizeof(head));
    tot = 1;
    for (int i = 1; i <= m; i++)
        if (w[i] > l)
            add(u[i], v[i], 1);
    ans += dinic();
    memset(head, 0, sizeof(head));
    tot = 1;
    for (int i = 1; i <= m; i++)
        if (w[i] < l)
            add(u[i], v[i], 1);
    ans += dinic();
    out << ans << '\n';
    return 0;
}

inline void add(int u, int v, int t) {
    ver[++tot] = v, flow[tot] = t, Next[tot] = head[u], head[u] = tot;
    ver[++tot] = u, flow[tot] = 0, Next[tot] = head[v], head[v] = tot;
}

bool bfs() {
    std::queue<int> q;
    memset(d, -1, sizeof(d));
    q.push(s);
    d[s] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if (flow[i] > 0 && d[y] == -1)
                d[y] = d[x] + 1, q.push(y);
        }
    }
    return d[t] >= 0;
}

int dfs(int x, int maxf) {
    if (x == t)
        return maxf;
    int tmp = maxf;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (d[y] == d[x] + 1 && flow[i] > 0) {
            int dlt = dfs(y, std::min(maxf, flow[i]));
            flow[i] -= dlt;
            flow[i ^ 1] += dlt;
            maxf -= dlt;
        }
    }
    return tmp - maxf;
}

int dinic() {
    int ret = 0;
    while (bfs())
        ret += dfs(s, 0x3f3f3f3f);
    return ret;
}