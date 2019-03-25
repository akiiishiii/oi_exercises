// 5251.cpp
#include <iostream>

int const Maxn = 2005, Mod = 998244353;
int n, k, x[Maxn], y[Maxn];

int power(int a, int p);
int lagrange(int n, int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i] >> y[i];
    std::cout << lagrange(n, k) << '\n';
    return 0;
}

int power(int a, int p) {
    if (p == 1)
        return a;
    int hh = power(a, p / 2);
    return (p & 1) ? 1ll * hh * hh % Mod * a % Mod : 1ll * hh * hh % Mod;
}

int lagrange(int n, int k) {
    int ans = 0, t1, t2;
    for (int i = 1; i <= n; ++i) {
        t1 = t2 = 1;
        for (int j = 1; j <= n; ++j) {
            if (i == j)
                continue;
            t1 = 1ll * t1 * (k - x[j]) % Mod;
            t2 = 1ll * t2 * (x[i] - x[j]) % Mod;
        }
        ans = (ans + 1ll * y[i] * t1 % Mod * power(t2, Mod - 2)) % Mod;
    }
    return ans < 0 ? ans + Mod : ans;
}