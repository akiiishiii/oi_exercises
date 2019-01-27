// 3252.cpp
#include <iostream>

int const Maxn = 50000;
int mb[Maxn + 10], prime[Maxn + 10], pnum;
bool vis[Maxn + 10];
long long sum[Maxn + 10];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, a, b, c, d, k;
    long long ans;
    mb[1] = 1;
    for (int i = 2; i <= Maxn; i++) {
        if (!vis[i])
            prime[++pnum] = i, mb[i] = -1;
        for (int j = 1; j <= pnum && i * prime[j] <= Maxn; j++) {
            if (!vis[prime[j] * i])
                vis[prime[j] * i] = true;
            if (!(i % prime[j]))
                break;
            mb[i * prime[j]] = -mb[i];
        }
    }
    for (int i = 1; i <= Maxn; i++)
        sum[i] = sum[i - 1] + mb[i];
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        ans = 0ll;
        std::cin >> a >> b >> c >> d >> k;
        if (b > d)
            std::swap(a, c), std::swap(b, d);
        a--, c--;
        a /= k, b /= k, c /= k, d /= k;
        for (int l = 1, r; l <= b; l = r + 1) {
            r = std::min(b / (b / l), d / (d / l));
            if (a >= l)
                r = std::min(r, a / (a / l));
            if (c >= l)
                r = std::min(r, c / (c / l));
            ans +=
                1ll * (sum[r] - sum[l - 1]) * (b / l - a / l) * (d / l - c / l);
        }
        std::cout << ans << '\n';
    }
    return 0;
}
