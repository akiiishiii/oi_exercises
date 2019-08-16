// 1028.cpp
#include <cstring>
#include <iostream>

struct tree {
    int ls = 0, rs = 0, v = 0;
} a[500];

int n, m, f[500][500], son[500] = {0};

int dp(int i, int j);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    memset(f, 0, sizeof f);
    std::cin >> n >> m;
    for (int i = 1, k, v; i <= n; i++) {
        std::cin >> k >> v;
        a[i].v = v;
        if (son[k] == 0)
            a[k].ls = i;
        else
            a[son[k]].rs = i;
        son[k] = i;
    }
    std::cout << dp(a[0].ls, m) << '\n';
    return 0;
}

int dp(int i, int j) {
    if (f[i][j] > 0)
        return f[i][j];
    if (i == 0 || j == 0)
        return 0;
    if (a[i].rs != 0)
        f[i][j] = dp(a[i].rs, j);
    for (int k = 0; k < j; k++)
        f[i][j] =
            std::max(f[i][j], dp(a[i].ls, k) + dp(a[i].rs, j - k - 1) + a[i].v);
    return f[i][j];
}