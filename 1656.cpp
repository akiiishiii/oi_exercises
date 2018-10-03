// 1656.cpp
#include <iostream>

int c[1001][1001];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, k, n, m;
    std::cin >> a >> b >> k >> n >> m;
    for (int i = 1; i <= k; i++)
        c[i][0] = c[i][i] = 1;
    for (int i = 2; i <= k; i++)
        for (int j = 1; j <= i - 1; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 10007;
    int ans = c[k][m], aa = 1, bb = 1;
    a %= 10007;
    b %= 10007;
    for (int i = 1; i <= n; i++)
        aa = aa * a % 10007;
    for (int i = 1; i <= m; i++)
        bb = bb * b % 10007;
    ans = ans * aa % 10007 * bb % 10007;
    std::cout << ans << '\n';
    return 0;
}
