// 2324.cpp
#include <cstring>
#include <iostream>

int const Maxn = 1010;
int n, m, root = 1, ans = 0, sum = 0;
int xs[Maxn], ys[Maxn], indeg[Maxn], now[Maxn], prt[Maxn], v[Maxn];

struct edges {
    int x, y, z;
    edges() = default;
    ~edges() = default;
    edges(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
} e[Maxn * Maxn];

void zhuliu();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> n) {
        sum = ans = 0;
        std::cin >> m;
        for (int i = 1; i <= n; i++)
            std::cin >> xs[i] >> ys[i];
        for (int i = 1, x, y; i <= m; i++) {
            std::cin >> x >> y;
            if (x != y)
                e[++sum] = edges(x, y, std::abs(xs[x] - xs[y]) + std::abs(ys[y] - ys[x]));
        }
        root = ++n;
        for (int i = 1; i < n; i++)
            e[++sum] = edges(n, i, 20000000);
        zhuliu();
        if (ans >= 40000000)
            std::cout << "Poor\n";
        else
            std::cout << ans - 20000000 << '\n';
    }
    return 0;
}

void zhuliu() {
    while (true) {
        int s = 0;
        memset(v, 0, sizeof(v));
        memset(now, 0, sizeof(now));
        for (int i = 1; i <= n; i++)
            indeg[i] = 0x7fffffff;
        for (int i = 1; i <= sum; i++)
            if (indeg[e[i].y] > e[i].z && e[i].x != e[i].y)
                prt[e[i].y] = e[i].x, indeg[e[i].y] = e[i].z;
        indeg[root] = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;
            ans += indeg[i];
            while (v[x] != i && !now[x] && x != root)
                v[x] = i, x = prt[x];
            if (x != root && !now[x]) {
                ++s;
                for (int j = prt[x]; j != x; j = prt[j])
                    now[j] = s;
                now[x] = s;
            }
        }
        if (!s)
            break;
        for (int i = 1; i <= n; i++)
            if (!now[i])
                now[i] = ++s;
        for (int i = 1; i <= sum; i++) {
            int y = e[i].y;
            e[i].x = now[e[i].x];
            e[i].y = now[e[i].y];
            if (e[i].x != e[i].y)
                e[i].z -= indeg[y];
        }
        n = s, root = now[root];
    }
}