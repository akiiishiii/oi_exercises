// 1655.cpp
#include <iostream>

int f[2010][2010], v[2010] = {0};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c, d, k;
    std::cin >> a >> b >> c >> d >> k;
    for (int i = 1; i <= c; i++)
        v[i] = d, f[i][0] = 1;
    for (int i = c + 1; i <= c + a; i++)
        v[i] = d + b, f[i][0] = 1;
    f[0][0] = 1;
    for (int i = 1; i <= a + c; i++)
        for (int j = 1; j <= k; j++)
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * (v[i] - j + 1)) % 100003;
    std::cout << f[a + c][k] << '\n';
    return 0;
}
