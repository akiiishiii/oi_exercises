// 1816.cpp
#include <iostream>
#include <cstring>

int m, n, tot;
long long f[13][8192];

bool check(int a, int b);
bool check(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> n >> m) {
        if ((n * m) & 1) {
            std::cout << "0\n";
            continue;
        }
        if (n < m)
            std::swap<int>(n, m);
        tot = 1 << m;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < tot; i++)
            if (check(i))
                f[1][i] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < tot; j++)
                for (int k = 0; k < tot; k++)
                    if (check(j, k))
                        f[i][j] += f[i - 1][k];
        std::cout << f[n][tot - 1] << '\n';
    }
    return 0;
}

bool check(int a, int b) {
    for (int i = 1; i < tot; i <<= 1) {
        if (!((a & i) || (b & i)))
            return false;
        if ((a & i) && (b & i)) {
            if ((a & (i << 1)) && ((b & (i << 1)))) {
                i <<= 1;
                continue;
            } else
                return false;
        }
    }
    return true;
}

bool check(int x) {
    int cnt;
    for (cnt = 0; x > 0; x >>= 1)
        if (x & 1)
            cnt++;
        else if (cnt & 1)
            return false;
    if (cnt & 1)
        return false;
    return true;
}