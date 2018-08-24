// 1430.cpp
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>

int a[2010][2010];
double d[2010];
bool v[2010];
int n, m;

void dijkstra(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int pa, pb;
    std::cin >> n >> m;
    memset(a, 0xcf, sizeof(a));
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        a[x][y] = std::max(a[x][y], 100 - z);
    }
    std::cin >> pa >> pb;
    dijkstra(pa);
    std::cout << std::fixed << std::setprecision(8) << 10000.0 / d[pb] << '\n';
    return 0;
}

void dijkstra(int mx) {
    for (int i = 1; i <= n; i++)
        d[i] = -200;
    memset(v, false, sizeof(v));
    d[mx] = 100;
    for (int i = 1; i < n; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++)
            if (!v[j] && (x == 0 || d[j] > d[x]))
                x = j;
        v[x] = true;
        for (int y = 1; y <= n; y++)
            d[y] = std::max(d[y], d[x] * (double)a[x][y] / 100.0);
    }
}