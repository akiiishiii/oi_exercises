// 2312.cpp
#include <iostream>
#include <cstring>

int my[105] = {0};
bool map[105][105], vst[105] = {false};
int n, m, k;

bool dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> k;
    for (int i = 1, j, x, y; i <= k; i++)
        std::cin >> j >> x >> y, map[x][y] = true;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vst, false, sizeof(vst));
        if (dfs(i))
            ans++;
    }
    std::cout << ans << '\n';
    return 0;
}

bool dfs(int x) {
    for (int i = 1; i <= m; i++)
        if (!vst[i] && map[x][i]) {
            vst[i] = true;
            if (!my[i] || dfs(my[i])) {
                my[i] = x;
                return true;
            }
        }
    return false;
}