// core.cpp
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("core.in");
std::ofstream out("core.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

//int const SIZE = 500005;
//int head[SIZE], ver[SIZE << 1], edge[SIZE << 1], Next[SIZE << 1];
//int tot, n, s, d1 = 0, d2 = 0;
//int f[SIZE], d[SIZE], prt[SIZE], w[SIZE];
int n, s, node = 1;
int f[301][301], dist[301][301], mat[301][301], prt[301], d[301], ond[301];
bool v[301], v2[301];

//inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void bfs();
int calc(int v, int u);
//void dfs(int x, int prt, int dist, int &p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> s;
    for (int i = 1, a, b, c; i < n; i++) {
        in >> a >> b >> c;
        //add(a, b, c), add(b, a, c);
        mat[a][b] = c;
        mat[b][a] = c;
        f[a][++f[a][0]] = b;
        f[b][++f[b][0]] = a;
    }
    //dfs(1, 0, 0, d2);
    //dfs(d2, 0, 0, d1);
    bfs();
    memset(prt, 0, sizeof(prt));
    bfs();
    int x = node, cnt = 0;
    while (x) {
        ond[++cnt] = x;
        x = prt[x];
    }
    for (int i = 1; i <= cnt; i++)
        for (int j = i + 1; j <= cnt; j++)
            dist[i][j] = dist[i][j - 1] + mat[ond[j - 1]][ond[j]];
    int ans = 0x3f3f3f3f;
    for (int i = 1, j; i <= cnt; i++) {
        memset(v2, false, sizeof(v2));
        for (j = i; j <= cnt && dist[i][j] <= s; j++)
            v2[ond[j]] = true;
        j--;
        ans = std::min(ans, calc(ond[i], ond[j]));
    }
    out << ans << '\n';
    return 0;
}

void bfs() {
    std::queue<int> q;
    memset(v, false, sizeof(v));
    memset(d, 0, sizeof(d));
    q.push(node);
    v[node] = true;
    int maxd = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (d[x] > maxd) {
            maxd = d[x];
            node = x;
        }
        for (int i = 1; i <= f[x][0]; i++) {
            int u = f[x][i];
            if (!v[u]) {
                v[u] = true;
                prt[u] = x;
                d[u] = d[x] + mat[x][u];
                q.push(u);
            }
        }
    }
    return;
}

int calc(int v, int u) {
    memset(prt, 0, sizeof(prt));
    node = v;
    bfs();
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int x = i, ans = 0;
        while (true) {
            if (v2[x])
                break;
            ans += mat[x][prt[x]];
            x = prt[x];
        }
        ret = std::max(ret, ans);
    }
    return ret;
}
/*
void dfs(int x, int prt, int dist, int &p) {
    if (dist > f[p])
        p = x;
    if (dist > f[x])
        f[x] = dist;
    for (int i = head[x]; i; i = Next[i]) {
        if (ver[i] != prt)
            dfs(ver[i], x, dist + edge[i], p);
    }
}
*/