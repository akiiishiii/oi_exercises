// 1570.cpp
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[]) {
    int mat[101][101], top[101], f[101] = {0}, indeg[101] = {0};
    int n, m;
    memset(mat, 0, sizeof(mat));
    std::cin >> n >> m;
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
            if (mat[top[j]][top[i]] > 0 && f[top[j]] + mat[top[j]][top[i]] > f[top[i]])
                f[top[i]] = f[top[j]] + mat[top[j]][top[i]];
    std::cout << f[top[n]] << '\n';
    return 0;
}
