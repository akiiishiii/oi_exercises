// 4129.cpp
#include <iostream>

int const N = 10000005;
long long const Mod = 100000009ll;
long long n, m, a, b, c, d, T, cnt;
long long prime[N], g[N], sum[N];
bool vis[N];

inline long long f(long long x, long long y) { return (x + 1) * x / 2 % Mod * ((y + 1) * y / 2 % Mod) % Mod; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    g[1] = sum[1] = 1;
    for (long long i = 2; i <= N - 5; i++) {
        if (!vis[i]) {
            prime[++prime[0]] = i;
            g[i] = ((-(i - 1) * i) % Mod + Mod) % Mod;
        }
        for (long long j = 1; j <= prime[0] && i * prime[j] <= N - 5; j++) {
            vis[i * prime[j]] = true;
            if (!(i % prime[j])) {
                g[i * prime[j]] = g[i] * prime[j] % Mod;
                break;
            }
            g[i * prime[j]] = g[i] * g[prime[j]] % Mod;
        }
        sum[i] = sum[i - 1] + g[i];
    }
    std::cin >> T;
    while (T--) {
        long long ans = 0;
        std::cin >> n >> m;
        if (n > m)
            std::swap(n, m);
        for (long long i = 1, j; i <= n; i = j + 1) {
            j = std::min(n / (n / i), m / (m / i));
            ans += f(n / i, m / i) * (sum[j] - sum[i - 1] + Mod) % Mod;
            ans %= Mod;
        }
        std::cout << ans << '\n';
    }
    return 0;
}