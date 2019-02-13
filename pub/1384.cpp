// 1384.cpp
#include <iostream>
#include <algorithm>
#include <cstring>

int f[105][105], a[105][105], r, c;

int dfs(int x, int y);

int main(int argc, char const *argv[]) {
    int ans = 0;
    memset(f, 0, sizeof(f));
    memset(a, 0, sizeof(a));
    std::cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            std::cin >> a[i][j];
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            ans = std::max(ans, dfs(i, j));
    std::cout << ans << '\n';
    return 0;
}

int dfs(int x, int y) {
    if (!x || !y || x == r + 1 || y == c + 1)
        return 0;
    if (f[x][y])
        return f[x][y];
    if (a[x - 1][y] < a[x][y])
        f[x][y] = std::max(f[x][y], dfs(x - 1, y));
    if (a[x + 1][y] < a[x][y])
        f[x][y] = std::max(f[x][y], dfs(x + 1, y));
    if (a[x][y - 1] < a[x][y])
        f[x][y] = std::max(f[x][y], dfs(x, y - 1));
    if (a[x][y + 1] < a[x][y])
        f[x][y] = std::max(f[x][y], dfs(x, y + 1));
    f[x][y]++;
    return f[x][y];
}