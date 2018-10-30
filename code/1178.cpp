// 1178.cpp
#include <iostream>

long long n, m, f[55][55];
int map[55][55];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char ch;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            std::cin >> ch;
            map[i][j] = (ch == '*');
        }
    long long b = f[1][1] = 1ll << n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            if (map[i][j]) {
                f[i + 1][j] += f[i][j] * 0.5;
                f[i + 1][j + 1] += f[i][j] * 0.5;
            }
            else
                f[i + 2][j + 1] += f[i][j];
        }
    if (!f[n + 1][m + 1]) {
        std::cout << "0/1\n";
        return 0;
    }
    while (!(f[n + 1][m + 1] % 2)) {
        f[n + 1][m + 1] /= 2;
        b /= 2;
    }
    std::cout << f[n + 1][m + 1] << '/' << b << '\n';
    return 0;
}