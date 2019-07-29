// 1172.cpp
#include <iomanip>
#include <iostream>

double f[15][15][15][15][5][5], ans;
bool vis[15][15][15][15][5][5];
int A, B, C, D;

double dp(int a, int b, int c, int d, int p, int q);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> A >> B >> C >> D;
    ans = dp(0, 0, 0, 0, 0, 0);
    if (ans > 100)
        std::cout << "-1.000\n";
    else
        std::cout << std::fixed << std::setprecision(3) << ans << '\n';
    return 0;
}

double dp(int a, int b, int c, int d, int p, int q) {
    if (vis[a][b][c][d][p][q])
        return f[a][b][c][d][p][q];
    vis[a][b][c][d][p][q] = true;
    double &ans = f[a][b][c][d][p][q];
    ans = 0;
    int x = a, y = b, z = c, w = d;
    if (p == 1)
        x++;
    else if (p == 2)
        y++;
    else if (p == 3)
        z++;
    else if (p == 4)
        w++;
    if (q == 1)
        x++;
    else if (q == 2)
        y++;
    else if (q == 3)
        z++;
    else if (q == 4)
        w++;
    if (x >= A && y >= B && z >= C && w >= D)
        return 0;
    int cnt = 54 - x - y - z - w;
    if (cnt <= 0)
        return ans = 1e10;
    if (a < 13)
        ans += dp(a + 1, b, c, d, p, q) * (13 - a) / cnt;
    if (b < 13)
        ans += dp(a, b + 1, c, d, p, q) * (13 - b) / cnt;
    if (c < 13)
        ans += dp(a, b, c + 1, d, p, q) * (13 - c) / cnt;
    if (d < 13)
        ans += dp(a, b, c, d + 1, p, q) * (13 - d) / cnt;
    if (!p) {
        double tmp = dp(a, b, c, d, 1, q);
        tmp = std::min(tmp, dp(a, b, c, d, 2, q));
        tmp = std::min(tmp, dp(a, b, c, d, 3, q));
        tmp = std::min(tmp, dp(a, b, c, d, 4, q));
        ans += tmp / cnt;
    }
    if (!q) {
        double tmp = dp(a, b, c, d, p, 1);
        tmp = std::min(tmp, dp(a, b, c, d, p, 2));
        tmp = std::min(tmp, dp(a, b, c, d, p, 3));
        tmp = std::min(tmp, dp(a, b, c, d, p, 4));
        ans += tmp / cnt;
    }
    return ++ans;
}