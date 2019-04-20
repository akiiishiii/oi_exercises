// 1029.cpp
#include <cstring>
#include <iostream>

int n, m;
long long f[110][210], g[110][210];
long long tmp1[210], tmp2[210];

void plus(long long a[], long long b[]);
void multiply(long long a[], long long k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    f[1][0] = 1;
    f[1][1] = m;
    f[2][0] = 1;
    f[2][1] = m * (m - 1);
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j <= g[i - 1][0]; j++)
            tmp1[j] = g[i - 1][j];
        for (int j = 0; j <= f[i - 1][0]; j++)
            tmp2[j] = f[i - 1][j];
        multiply(tmp1, m - 1);
        multiply(tmp2, m - 2);
        plus(tmp1, tmp2);
        for (int j = 0; j <= tmp1[0]; j++)
            f[i][j] = tmp1[j];
        for (int j = 0; j <= f[i - 1][0]; j++)
            g[i][j] = f[i - 1][j];
        memset(tmp1, 0, sizeof(tmp1));
        memset(tmp2, 0, sizeof(tmp2));
    }
    for (int i = f[n][0]; i >= 1; i--)
        std::cout << f[n][i];
    std::cout << '\n';
    return 0;
}

void plus(long long a[], long long b[]) {
    a[0] = std::max(a[0], b[0]);
    for (int i = 1; i <= std::min(a[0], b[0]); i++)
        a[i] += b[i];
    for (int i = 1; i <= a[0]; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    if (a[a[0] + 1] > 0)
        a[0]++;
}

void multiply(long long a[], long long k) {
    for (int i = 1; i <= a[0]; i++)
        a[i] = a[i] * k;
    for (int i = 1; i <= a[0]; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    while (a[a[0] + 1] > 0) {
        a[0]++;
        a[a[0] + 1] = a[a[0]] / 10;
        a[a[0]] %= 10;
    }
}