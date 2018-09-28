// 1643.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m = 0, n, d = 1, phi, no;
    int p[3402] = {0}, c[3402] = {0};
    std::cin >> n;
    no = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p[++m] = i, c[m] = 0;
            while (!(n % i))
                n /= i, c[m]++;
        }
    }
    if (n > 1)
        p[++m] = n, c[m] = 1;
    for (int i = 1; i <= m; i++)
        d *= c[i] + 1;
    phi = no;
    for (int i = 1; i <= m; i++)
        if (c[m])
            phi = phi / p[i] * (p[i] - 1);
    std::cout << no - d - phi + 1 << '\n';
    return 0;
}