#include <iostream>

long long const Mod = 100000007;
int n, m;
long long f[1000005];

inline long long power(long long d, int m);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    long long tmp = 2;
    for (long long i = 3, base = power(2, n) - 1, bt = base; i <= m; i++) {
        tmp = tmp * i % Mod;
        bt = bt * (base - i + 2) % Mod;
        f[i] = (bt + (Mod - f[i - 1]) + (Mod - f[i - 2] * (i - 1) % Mod * (base - (i - 2) + Mod) % Mod)) % Mod;
    }
    std::cout << f[m] * power(tmp, Mod - 2) % Mod << '\n';
}

inline long long power(long long d, int m) {
    long long ans = 1;
    d %= Mod;
    while (m) {
        if (m & 1)
            ans = ans * d % Mod;
        m >>= 1;
        d = d * d % Mod;
    }
    return ans;
}