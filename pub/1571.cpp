// 1570.cpp
#include <iostream>
#include <cstring>

void dfs(int now);

int prt[102] = {0};

int main(int argc, char const *argv[]) {
    int mat[102][102], top[102], f[102] = {0}, indeg[102] = {0};
    int n, m;
    memset(mat, 0, sizeof(mat));
    std::cin >> n >> m;
    n++;
    for (int i = 1, x, y, z; i <= m; i++) {
        std::cin >> x >> y >> z;
        mat[x][y] = z;
        indeg[y]++;
    }
    for (int i = 1, j; i <= n; i++) {
        for (j = 1; j <= n && indeg[j] > 0; j++);
        top[i] = j;
        indeg[j] = 0x3f3f3f3f;
        for (int k = 1; k <= n; k++)
            if (mat[j][k] > 0)
                indeg[k]--;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i - 1; j++)
            if (mat[top[j]][top[i]] > 0 && f[top[j]] + mat[top[j]][top[i]] > f[top[i]]) {
                f[top[i]] = f[top[j]] + mat[top[j]][top[i]];
                prt[top[i]] = top[j];
            }
    std::cout << f[top[n]] << '\n';
    dfs(top[n]);
    std::cout << '\n';
    return 0;
}

void dfs(int now) {
    if (prt[now])
        dfs(prt[now]);
    std::cout << now << ' ';
}