#include <algorithm>
#include <cstring>
#include <iostream>

int const Maxn = 200002;
int tot, n, m;
int siz[Maxn], prt[Maxn], val[Maxn], sum[Maxn];
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];

struct edges {
    int a, b, w;
    bool operator<(edges const &e) const { return w > e.w; }
} e[100002];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
int search(int x) { return (x == prt[x] ? x : search(prt[x])); }
void dfs(int x);
void ex_kruskal();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, ans;
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        std::cin >> n;
        m = n - 1;
        ans = tot = 0;
        memset(head, 0, sizeof(head));
        for (int i = 1; i <= m; i++)
            std::cin >> e[i].a >> e[i].b >> e[i].w;
        ex_kruskal();
        dfs((n << 1) - 1);
        for (int i = 1; i <= (n << 1) - 1; i++)
            ans = std::max(ans, sum[i]);
        std::cout << "Case " << t << ": " << ans << '\n';
    }
}

void dfs(int x) {
    int num = 0;
    sum[x] = siz[x] = 0;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        num++;
        dfs(y);
        if (y > n && num == 1)
            sum[x] = sum[y];
        if (siz[x])
            sum[x] = std::max(sum[x] + val[x] * siz[y], sum[y] + siz[x] * val[x]);
        siz[x] += siz[y];
    }
    if (!head[x])
        siz[x] = 1;
}

void ex_kruskal() {
    int cnt = n, tot = n << 1;
    std::sort(e + 1, e + 1 + m);
    for (int i = 1; i <= tot; i++)
        prt[i] = i;
    for (int i = 1, p1, p2; i <= m; i++) {
        p1 = search(e[i].a), p2 = search(e[i].b);
        if (p1 != p2) {
            prt[p1] = prt[p2] = ++cnt;
            val[cnt] = e[i].w;
            add(cnt, p1), add(cnt, p2);
            if (cnt == tot - 1)
                break;
        }
    }
}