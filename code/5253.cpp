// 5253.cpp
#include <cstring>
#include <iostream>
#include <queue>

int const Maxv = 400 * 400 + 10;
int mx[405][405], d[Maxv];
int head[Maxv], ver[Maxv * 6], edge[Maxv * 6], Next[Maxv * 6], tot;
bool v[Maxv];
int s, t;

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
int spfa();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        int n, x, rx, dx;
        tot = 0;
        memset(head, 0, sizeof(head));
        std::cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                std::cin >> mx[i][j];
        s = 0, t = (n - 1) * (n - 1) + 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                x = (i - 1) * (n - 1) + j;
                rx = x + 1, dx = x + n - 1;
                if (j < n - 1)
                    add(x, rx, mx[i][j + 1]), add(rx, x, mx[i][j + 1]);
                if (i < n - 1)
                    add(x, dx, mx[i + 1][j]), add(dx, x, mx[i + 1][j]);
            }
        }
        for (int j = 1; j < n; j++)
            add(s, j, mx[1][j]), add((n - 2) * (n - 1) + j, t, mx[n][j]);
        for (int i = 1; i < n; i++)
            add(s, i * (n - 1), mx[i][n]), add((i - 1) * (n - 1) + 1, t, mx[i][1]);
        std::cout << spfa() << '\n';
    }
    return 0;
}

int spfa() {
    std::queue<int> q;
    memset(v, 0, sizeof(v));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0, v[s] = true;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[x] + z < d[y]) {
                d[y] = d[x] + z;
                if (!v[y])
                    v[y] = true, q.push(y);
            }
        }
    }
    return d[t];
}