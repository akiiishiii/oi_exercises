// 2529.cpp
#include <iostream>
#include <cstring>

int my[505] = {0};
bool map[505][505], vst[505] = {false};
int n, k;

bool dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> k;
    for (int i = 1, r, c; i <= k; i++)
        std::cin >> r >> c, map[r][c] = true;
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
    for (int i = 1; i <= n; i++)
        if (!vst[i] && map[x][i]) {
            vst[i] = true;
            if (!my[i] || dfs(my[i])) {
                my[i] = x;
                return true;
            }
        }
    return false;
}