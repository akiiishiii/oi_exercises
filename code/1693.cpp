// 1693.cpp
#include <iostream>
#include <cstring>
#include <cmath>

int n;
double ans[105] = {0}, m[101][102];

void solve(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(m, 0, sizeof m);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            std::cin >> m[i][j];
    for (int i = 1; i <= n; i++)
        solve(i);
    for (int i = n; i > 0; i--) {
        for (int j = n; j > i; j--)
            m[i][n + 1] -= m[i][j] * ans[j];
        ans[i] = m[i][n + 1] / m[i][i];
    }
    for (int i = 1; i <= n; i++)
        std::cout << int(ans[i] + 0.5) << ' ';
    std::cout << '\n';
    return 0;
}

void solve(int x) {
    int k = x;
    double p, maxx = fabs(m[x][x]);
    for (int i = x + 1; i <= n; i++)
        if (fabs(m[i][x]) > maxx) {
            maxx = fabs(m[i][x]);
            k = i;
        }
    if (k != x)
        for (int i = x; i <= n + 1; i++)
            std::swap(m[x][i], m[k][i]);
    for (int i = x + 1; i <= n; i++) {
        p = m[i][x] / m[x][x];
        for (int j = x; j <= n + 1; j++)
            m[i][j] -= p * m[x][j];
    }
}
