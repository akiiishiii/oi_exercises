// 1633.cpp
#include <iostream>
#include <cstring>

int v[1000001], prime[50001];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int l, r, ans = 0;
    memset(v, 0, sizeof(v));
    int t = 0;
    for (int i = 2; i <= 50000; i++) {
        if (!v[i]) {
            v[i] = i;
            prime[++t] = i;
        }
        for (int j = 1; j <= t; j++) {
            if (prime[j] > v[i] || prime[j] > 50000 / i)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
    memset(v, 0, sizeof(v));
    std::cin >> l >> r;
    for (int i = 1; i <= t; i++) {
        int j = l / prime[i];
        if (j * prime[i] < l)
            j++;
        if (j == 1)
            j++;
        for (; (long long)j * prime[i] <= r; j++)
            v[j * prime[i] - l] = 1;
    }
    for (int i = 0; i <= r - l; i++)
        if (!v[i])
            ans++;
    std::cout << ans << '\n';
    return 0;
}