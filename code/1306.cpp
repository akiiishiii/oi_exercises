// 1306.cpp
#include <iostream>

int a, b, m, ans = 1, mod = 9901;
int p[20], c[20];

void divide(int n);
int power(int a, long long b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> a >> b;
    divide(a);
    for (int i = 1; i <= m; i++) {
        if ((p[i] - 1) % mod == 0) {
            ans = ((long long)b * c[i] + 1) % mod * ans % mod;
            continue;
        }
        int x = power(p[i], (long long)b * c[i] + 1);
        x = (x - 1 + mod) % mod;
        int y = p[i] - 1;
        y = power(y, mod - 2);
        ans = (long long)ans * x % mod * y % mod;
    }
    std::cout << ans << '\n';
    return 0;
}

void divide(int n) {
    m = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p[++m] = i, c[m] = 0;
            while (n % i == 0)
                n /= i, c[m]++;
        }
    }
    if (n > 1)
        p[++m] = n, c[m] = 1;
}

int power(int a, long long b) {
    int c = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            c = (long long)c * a % mod;
        a = (long long)a * a % mod;
    }
    return c;
}