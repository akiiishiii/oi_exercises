// 1357.cpp
#include <iostream>
#include <cmath>

int const Maxn = 10000005;
bool vis[Maxn];
int prime[Maxn], mu[Maxn];
long long f[Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    mu[1] = 1;
    for (int i = 2; i <= 1e7; i++) {
        if (!vis[i])
            mu[i] = -1, prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= 1e7; j++) {
            vis[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
            else
                mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        int tp = prime[i];
        for (int j = 1; j * tp <= 1e7; j++)
            f[j * tp] += mu[j];
    }
    for (int i = 1; i <= 1e7; i++)
        f[i] += f[i - 1];
    long long ans = 0, j;
    std::cin >> n;
    for (int i = 1; i <= n; i = j + 1) {
        j = n / (n / i);
        ans += (f[j] - f[i - 1]) * (n / i) * (n / i);
    }
    std::cout << ans << '\n';
    return 0;
}