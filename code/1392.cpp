// 1392.cpp
#include <cmath>
#include <iostream>

int const Maxn = 50005;
bool vis[Maxn];
int prime[Maxn], mu[Maxn];

long long ask(long long x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, T;
    mu[1] = 1;
    for (int i = 2; i <= 50000; i++) {
        if (!vis[i])
            mu[i] = -1, prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= 50000; j++) {
            vis[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
            else
                mu[i * prime[j]] = -mu[i];
        }
    }
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        long long l = n, r = 2e9, mid, ans;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (ask(mid) >= n)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        std::cout << ans << '\n';
    }
    return 0;
}

long long ask(long long x) {
    long long sum = 0;
    int lim = sqrt(x);
    for (int i = 1; i <= lim; i++)
        sum += x / (i * i) * mu[i];
    return sum;
}