// 1645.cpp
#include <iostream>

int v[50001] = {0}, prime[50001] = {0};
int ans, a0, a1, b0, b1, m;

void primes(int n);
void check(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    primes(50000);
    while (n--) {
        ans = 1;
        std::cin >> a0 >> a1 >> b0 >> b1;
        for (int i = 1; i <= m && ans; i++)
            if (!(b1 % prime[i]))
                check(prime[i]);
        if (b1 > 1)
            check(b1);
        std::cout << ans << '\n';
    }
    return 0;
}

void primes(int n) {
    m = 0;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            v[i] = i;
            prime[++m] = i;
        }
        for (int j = 1; j <= m; j++) {
            if (prime[j] > v[i] || prime[j] > n/i) break;
            v[i*prime[j]] = prime[j];
        }
    }
}

void check(int x) {
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    while (!(a0 % x)) {
        a0 /= x;
        t1++;
    }
    while (!(a1 % x)) {
        a1 /= x;
        t2++;
    }
    while (!(b0 % x)) {
        b0 /= x;
        t3++;
    }
    while (!(b1 % x)) {
        b1 /= x;
        t4++;
    }
    if (t2 > t1 || t3 > t4 || (t1 > t2 && t4 > t3 && t4 > t2))
        ans = 0;
    else if (t1 == t2 && t3 == t4)
        ans *= t4 - t2 + 1;
}
