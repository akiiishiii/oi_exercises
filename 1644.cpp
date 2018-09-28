// 1644.cpp
#include <iostream>
#include <cstring>

const int MAX_N = 1000001;
long long v[MAX_N] = {0}, prime[MAX_N] = {0}, phi[MAX_N] = {0};
int m;

void euler(int n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    euler(1000000);
    for (int i = 3; i <= 1000000; i++)
        phi[i] += phi[i - 1];
    while (std::cin >> n && n)
        std::cout << phi[n] << '\n';
    return 0;
}

void euler(int n) {
    m = 0;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            v[i] = i, prime[++m] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= m; j++) {
            if (prime[j] > v[i] || prime[j] > n / i)
                break;
            v[i * prime[j]] = prime[j];
            phi[i * prime[j]] = phi[i] * (i % prime[j] ? prime[j] - 1 : prime[j]);
        }
    }
}
