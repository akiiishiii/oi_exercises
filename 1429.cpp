// Dijkstra算法，O(n^2)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int a[1010][1010], b[1010][1010], da[1010], db[1010];
bool v[1010];
int n, m;

void dijkstra(int mx, int map[1010][1010], int *md);

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, maxx = 0;
    std::cin >> n >> m >> x;
    memset(a, 0x3f, sizeof(a));
    memset(b, 0x3f, sizeof(b));
    memset(da, 0x3f, sizeof(da));
    memset(db, 0x3f, sizeof(db));
    for (int i = 1; i <= n; i++) a[i][i] = b[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        a[x][y] = std::min(a[x][y], z);
        b[y][x] = std::min(b[y][x], z);
    }
    dijkstra(x, a, da);
    dijkstra(x, b, db);
    for (int i = 1; i <= n; i++)
        maxx = std::max(da[i] + db[i], maxx);
    std::cout << maxx << '\n';
    return 0;
}

void dijkstra(int mx, int map[1010][1010], int *md) {
    memset(v, 0, sizeof(v));
    md[mx] = 0;
    for (int i = 1; i < n; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++)
            if (!v[j] && (x == 0 || md[j] < md[x])) x = j;
        v[x] = 1;
        for (int y = 1; y <= n; y++)
            md[y] = std::min(md[y], md[x] + map[x][y]);
    }
}