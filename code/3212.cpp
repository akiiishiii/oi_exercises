// 3212.cpp
#include <iostream>

int n, k;
long long a[105], b[105];

void gauss();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    gauss();
    for (int i = 1; i <= n; i++)
        ans += a[i];
    std::cout << ans << '\n';
    return 0;
}

void gauss() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            if (a[j] > a[i])
                std::swap(a[i], a[j]);
        if (!a[i]) {
            k = i - 1;
            break;
        }
        for (int j = 62; j >= 0; j--)
            if ((a[i] >> j) & 1) {
                b[i] = j;
                for (k = 1; k <= n; k++)
                    if (k != i && (a[k] >> j) & 1)
                        a[k] ^= a[i];
                break;
            }
    }
    long long now = 0;
    for (int i = 1; i <= k; i++)
        now ^= a[i];
    a[1] = now;
    for (int i = 2; i <= k; i++)
        a[i] ^= now;
    for (int i = k + 1; i <= n; i++)
        a[i] = now;
}