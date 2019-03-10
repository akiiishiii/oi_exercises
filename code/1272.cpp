// 1272.cpp
#include <iostream>

long long const mod = 1e9 + 7;
long long a[405][805];
int n, m;

long long power(long long x);
int dl(int x);
int gauss();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    bool flag;
    std::cin >> n;
    m = n * 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> a[i][j], a[i][j + n] = (i == j);
    flag = gauss();
    if (flag)
        for (int i = 1; i <= n; i++) {
            for (int j = n + 1; j <= m; j++) {
                if (a[i][j] < 0)
                    a[i][j] += mod;
                std::cout << a[i][j] << ' ';
            }
            std::cout << '\n';
        }
    else {
        std::cout << "No Solution\n";
        return 0;
    }
}

long long power(long long x) {
    long long ans = 1, y;
    x %= mod;
    y = mod - 2;
    while (y) {
        if (y & 1)
            ans = (ans * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return ans % mod;
}

int dl(int x) {
    long long maxx = std::abs(a[x][x]), p, tmp;
    int k = x;
    for (int i = x + 1; i <= n; i++)
        if (std::abs(a[i][x]) > maxx)
            maxx = std::abs(a[i][x]), k = i;
    if (k != x)
        std::swap(a[k], a[x]);
    if (!a[x][x])
        return false;
    p = power(a[x][x]);
    for (int i = 1; i <= n; i++)
        if (i != x) {
            tmp = (a[i][x] * p) % mod;
            for (int j = x; j <= m; j++)
                a[i][j] = (a[i][j] - a[x][j] * tmp % mod) % mod;
        }
    for (int i = x; i <= m; i++)
        a[x][i] = a[x][i] * p % mod;
    return true;
}

int gauss() {
    bool flag;
    for (int i = 1; i <= n; i++) {
        flag = dl(i);
        if (!flag)
            return false;
    }
    return true;
}