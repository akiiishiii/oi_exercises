// 1447.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

int const Maxn = 3005, Num = 1919, Mod = 10000007;
int dfn[Maxn], hash[Maxn], g[52][52];
int m, n, root, cnt;

int calc(int l, int r, int *a);
void dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m;
    std::cin >> m >> n;
	for (int i = 1; i <= m; i++) {
        memset(g, 0, sizeof(g));
        int deg[102] = {0};
        for (int j = 1, x, y; j < n; j++) {
            std::cin >> x >> y;
            g[x][y] = 1;
            deg[y]++;
        }
        for (int j = 1; j <= n; j++)
            if (!deg[j]) {
                root = j;
                break;
            }
        cnt = 0;
        dfs(root);
        hash[i] = calc(2, cnt - 1, dfn);
    }
    for (int i = 1; i <= m; i++)
        if (hash[i] != -0x3f3f3f3f) {
            std::cout << i;
            for (int j = i + 1; j <= m; j++)
                if (hash[i] == hash[j]) {
                    std::cout << '=' << j;
                    hash[j] = -0x3f3f3f3f;
                }
            std::cout << '\n';
        }
    return 0;
}

int calc(int l, int r, int *a) {
    if (l + 1 == r)
        return 1;
    int rec = 1007, tot = 0, dfn[Maxn], j, tmp;
    for (int i = l; i <= r; i = j + 1) {
        for (tmp = 0, j = i; j <= r; j++) {
            tmp += a[j];
            if (!tmp)
                break;
        }
        dfn[++tot] = calc(i + 1, j - 1, a);
    }
    std::sort(dfn + 1, dfn + tot + 1);
    for (int i = 1; i <= tot; i++)
        rec = ((rec * Num) ^ dfn[i]) % Mod;
    return rec;
}

void dfs(int x) {
    dfn[++cnt] = -1;
    for (int i = 1; i <= n; i++)
        if (g[x][i])
            dfs(i);
    dfn[++cnt] = 1;
}