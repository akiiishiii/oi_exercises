// 4043.cpp
#include <iomanip>
#include <iostream>

int const Maxn = 105, Maxm = 10005;

int n, k, v, cnt = 0, pre[Maxn], id[Maxn], vis[Maxn], b[Maxn];
double a[Maxn], low[Maxn], in[Maxn], ans;

struct edge {
    int u, v;
    double w;
    edge() = default;
    ~edge() = default;
    edge(int u, int v, double w) : u(u), v(v), w(w) {}
} e[Maxm];

double zhuliu(int rt);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    v = n + 1;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i] >> b[i], low[i] = a[i], e[cnt++] = edge(0, i, b[i] ? a[i] : 0);
    std::cin >> k;
    for (int i = 1, u, v; i <= k; ++i) {
        double w;
        std::cin >> u >> v >> w;
        if (b[u] && b[v])
            e[cnt++] = edge(u, v, w), low[v] = std::min(low[v], w);
    }
    ans = zhuliu(0);
    for (int i = 1; i <= n; ++i)
        if (b[i])
            ans += low[i] * (b[i] - 1);
    std::cout << std::fixed << std::setprecision(2) << ans << '\n';
    return 0;
}

double zhuliu(int rt) {
    double ret = 0;
    while (true) {
        for (int i = 0; i < v; ++i)
            in[i] = 1e30, id[i] = -1, vis[i] = -1;
        for (int i = 0; i < cnt; ++i) {
            int u = e[i].u, v = e[i].v;
            double w = e[i].w;
            if (w < in[v] && v != u)
                pre[v] = u, in[v] = w;
        }
        in[rt] = 0;
        pre[rt] = rt;
        for (int i = 0; i < v; ++i) {
            if (in[i] == 1e30)
                return -1;
            ret += in[i];
        }
        int num = 0;
        for (int i = 0; i < v; ++i) {
            int u = i;
            while (vis[u] == -1)
                vis[u] = i, u = pre[u];
            if (vis[u] != i || u == rt)
                continue;
            for (int t = pre[u]; t != u; t = pre[t])
                id[t] = num;
            id[u] = num++;
        }
        if (!num)
            break;
        for (int i = 0; i < v; ++i)
            if (id[i] == -1)
                id[i] = num++;
        for (int i = 0; i < cnt; ++i)
            e[i].w -= in[e[i].v], e[i].u = id[e[i].u], e[i].v = id[e[i].v];
        v = num;
        rt = id[rt];
    }
    return ret;
}