// 2922.cpp
#include <iomanip>
#include <iostream>

int n, m, t, tot;
int head[10001], ver[10001], Next[10001], d[10001];
bool map[51][51];
double f[501][51][51];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> t;
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y, add(x, y);
        map[x][y] = true;
        d[x]++;
    }
    f[0][1][1] = 1.00;
    for (int w = 0; w <= t; w++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (f[w][i][j] > 0) {
                    bool flag = map[i][j];
                    for (int k = head[i]; k; k = Next[k]) {
                        int y = ver[k];
                        if (y == j)
                            continue;
                        f[w + 1][y][i] += f[w][i][j] * 1.00 / (double)(d[i] + !flag);
                    }
                    f[w + 1][i][j] += f[w][i][j] * 1.00 / (double)(d[i] + !flag);
                }
    for (int i = 1; i <= n; i++) {
        double ans = 0;
        for (int j = 1; j <= n; j++)
            ans += f[t][i][j];
        std::cout << std::fixed << std::setprecision(3) << ans * 100 << '\n';
    }
    return 0;
}