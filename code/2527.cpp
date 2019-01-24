// 2527.cpp
#include <iostream>
#include <cstring>

int const Maxn = 205;
int n, m;
int my[Maxn];
bool vst[Maxn], g[Maxn][Maxn];

bool dfs(int i);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, tmp; i <= n; i++)
        while (std::cin >> tmp && tmp)
            g[i][tmp] = true;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vst, false, sizeof(vst));
        if (dfs(i))
            ans++;
    }
    std::cout << ans << '\n';
    return 0;
}

bool dfs(int i) {
    for (int j = 1; j <= m; j++)
        if (g[i][j] && !vst[j]) {
            vst[j] = true;
            if (!my[j] || dfs(my[j])) {
                my[j] = i;
                return true;
            }
        }
    return false;
}