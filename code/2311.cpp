// 2311.cpp
#include <cstring>
#include <iostream>

int n, m, tn, pn;
int a[10000][200], map[210][210], c1[210][210], c2[210][210], match[10000];
bool ychk[10000];

bool dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> map[i][j];
    for (int i = 1; i <= n; i++)
        map[i][0] = 2;
    for (int j = 1; j <= m; j++)
        map[0][j] = 2;
    k = tn = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] != 2) {
                if (map[i][j - 1] != 2)
                    c1[i][j] = k;
                else
                    c1[i][j] = ++k;
                if (k > tn)
                    tn = k;
            }
    k = pn = 0;
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            if (map[i][j] != 2) {
                if (map[i - 1][j] != 2)
                    c2[i][j] = k;
                else
                    c2[i][j] = ++k;
                if (k > pn)
                    pn = k;
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!map[i][j]) {
                k = c1[i][j];
                a[k][++a[k][0]] = c2[i][j];
            }
    int ans = 0;
    for (int i = 1; i <= tn; i++) {
        memset(ychk, false, sizeof(ychk));
        ans += dfs(i);
    }
    std::cout << ans << '\n';
    return 0;
}

bool dfs(int x) {
    for (int i = 1; i <= a[x][0]; i++)
        if (!ychk[a[x][i]]) {
            ychk[a[x][i]] = true;
            if (!match[a[x][i]] || dfs(match[a[x][i]])) {
                match[a[x][i]] = x;
                return true;
            }
        }
    return false;
}