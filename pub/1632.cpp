// 1632.cpp
#include <iostream>
#include <cstring>

int const MAX_N = 1000005;
int v[MAX_N], prime[MAX_N];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n;
    memset(v, 0, sizeof(v));
    int t = 0;
    for (int i = 2; i <= 1000000; i++) {
        if (!v[i]) {
            v[i] = i;
            prime[++t] = i;
        }
        for (int j = 1; j <= t; j++) {
            if (prime[j] > v[i] || prime[j] > 1000000 / i)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
    while (std::cin >> m >> n) {
        int ans = 0;
        for (int i = m; i <= n; i++)
            if (v[i] == i)
                ans++;
        std::cout << ans << '\n';
    }
    return 0;
}