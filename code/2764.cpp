// 2764.cpp
#include <iostream>
#include <algorithm>

int const SIZE = 100005;
int head[SIZE], ver[SIZE << 1], edge[SIZE << 1], Next[SIZE << 1];
int pairs[SIZE], size[SIZE], nodes[SIZE];
int tot, n, k, ans = 0;
bool v[SIZE] = {false};

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void dfs(int x, int num);
void findcenter(int x, int prt, int num, int &c, int &maxc);
void calc(int x, int len, int sign);
void dfs2(int x, int prt, int dist, int &cnt);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> k;
    for (int i = 1, u, v, l; i < n; i++) {
        std::cin >> u >> v >> l;
        ::add(u, v, l), ::add(v, u, l);
    }
    ::dfs(1, n);
    std::cout << ans << '\n';
    return 0;
}

void dfs(int x, int num) {
    int maxc = 0x3f3f3f3f, core;
    ::findcenter(x, 0, num, core, maxc);
    ::calc(core, 0, 1);
    v[core] = true;
    for (int i = head[core]; i; i = Next[i]) {
        int y = ver[i];
        if (!v[y]) {
            ::calc(y, edge[i], -1);
            ::dfs(y, nodes[y]);
        }
    }
}

void findcenter(int x, int prt, int num, int &c, int &maxc) {
    size[x] = 1;
    int s = 0;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt || v[y])
            continue;
        ::findcenter(y, x, num, c, maxc);
        size[x] += size[y];
        s = std::max(s, size[y]);
    }
    s = std::max(s, num - size[x]);
    if (s < maxc)
        maxc = s, c = x;
}

void calc(int x, int len, int sign) {
    int cnt = 0;
    ::dfs2(x, x, len, cnt);
    std::sort(pairs + 1, pairs + cnt + 1);
    int l = 1, r = cnt;
    while (l < r) {
        if (pairs[l] + pairs[r] <= k)
            ans += (r - l++) * sign;
        else
            r--;
    }
}

void dfs2(int x, int prt, int dist, int &cnt) {
    pairs[++cnt] = dist;
    nodes[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (v[y] || y == prt)
            continue;
        ::dfs2(y, x, dist + edge[i], cnt);
        nodes[x] += nodes[y];
    }
}