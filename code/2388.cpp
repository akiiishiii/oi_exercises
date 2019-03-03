// 2388.cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

int const Maxn = 105, Maxm = 1005, Mod = 31011;
int prt[Maxn], ptmp[Maxn], g[Maxn][Maxn], mat[Maxn][Maxn];
std::vector<int> vec[Maxn];
bool vis[Maxn];
int n, m;

struct edges {
    int u, v, w;
    bool operator<(const edges &e) const { return w < e.w; }
} e[Maxm];

int search(int x, int p[]) { return (x == p[x] ? x : search(p[x], p)); }
int det(int a[][Maxn], int n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++)
        vec[i].clear();
    for (int i = 0; i < m; i++)
        std::cin >> e[i].u >> e[i].v >> e[i].w;
    std::sort(e, e + m);
    for (int i = 1; i <= n; i++)
        prt[i] = i, vis[i] = false;
    int edge = -1, ans = 1;
    for (int k = 0; k <= m; k++) {
        if (e[k].w != edge || k == m) {
            for (int i = 1; i <= n; i++)
                if (vis[i]) {
                    int u = search(i, ptmp);
                    vec[u].push_back(i);
                    vis[i] = false;
                }
            for (int i = 1; i <= n; i++) {
                if (vec[i].size() > 1) {
                    for (int a = 1; a <= n; a++)
                        for (int b = 1; b <= n; b++)
                            mat[a][b] = 0;
                    int len = vec[i].size();
                    for (int a = 0; a < len; a++)
                        for (int b = a + 1; b < len; b++) {
                            int p1 = vec[i][a], p2 = vec[i][b];
                            mat[a][b] -= g[p1][p2], mat[b][a] = mat[a][b];
                            mat[a][a] += g[p1][p2], mat[b][b] += g[p1][p2];
                        }
                    int ret = (int)det(mat, len);
                    ans = (ans * ret) % Mod;
                    for (int a = 0; a < len; a++)
                        prt[vec[i][a]] = i;
                }
            }
            for (int i = 1; i <= n; i++)
                ptmp[i] = prt[i] = search(i, prt), vec[i].clear();
            if (k == m)
                break;
            edge = e[k].w;
        }
        int a = e[k].u, b = e[k].v;
        int p1 = search(a, prt), p2 = search(b, prt);
        if (p1 == p2)
            continue;
        vis[p1] = vis[p2] = true;
        ptmp[search(p1, ptmp)] = search(p2, ptmp);
        g[p1][p2]++, g[p2][p1]++;
    }
    bool flag = false;
    for (int i = 2; i <= n && !flag; i++)
        if (ptmp[i] != ptmp[i - 1])
            flag = true;
    if (!m)
        flag = true;
    std::cout << (flag ? 0 : ans % Mod) << '\n';
    return 0;
}

int det(int a[][Maxn], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] %= Mod;
    int ret = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            while (a[j][i]) {
                int t = a[i][i] / a[j][i];
                for (int k = i; k < n; k++)
                    a[i][k] = (a[i][k] - a[j][k] * t) % Mod;
                for (int k = i; k < n; k++)
                    std::swap(a[i][k], a[j][k]);
                ret = -ret;
            }
        if (!a[i][i])
            return 0;
        ret = ret * a[i][i] % Mod;
    }
    return (ret + Mod) % Mod;
}