// 1119_.cpp
#include <iostream>
#include <cstring>

long long f[15][11];
int num[15] = {0};

long long query(long long n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    f[1][4] = 0;
    for (int i = 2; i <= 15; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (!((j == 6 && k == 2) || j == 4 || k == 4))
                    f[i][j] += f[i - 1][k];
    long long x, y;
    while (std::cin >> x >> y) {
        if (!(x || y))
            break;
        std::cout << query(y) - query(x - 1) << '\n';
    }
    return 0;
}

long long query(long long n) {
    if (!n)
        return 1;
    long long ans = 0;
    num[0] = 0;
    while (n) {
        num[++num[0]] = n % 10;
        n /= 10;
    }
    for (int i = num[0]; i >= 1; i--) {
        for (int j = 0; j < num[i]; j++)
            if (!((num[i + 1] == 6 && j == 2) || j == 4))
                ans += f[i][j];
        if (num[i] == 4 || (num[i] == 2 && num[i + 1] == 6))
            break;
        if (i == 1)
            ans += f[1][num[1]];
    }
    return ans;
}