// 5231.cpp
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

long long cnt = 0, a[10005];

long long gcd(long long a, long long b) { return a % b ? gcd(b, a % b) : b; }
long long multi(long long a, long long b, long long mod);
bool miller_rabin(long long n);
long long power(long long a, long long b, long long p);
long long pollard_rho(long long n, int c);
void findfact(long long n, int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    srand((unsigned)time(NULL));
    int T;
    long long n;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        if (miller_rabin(n))
            std::cout << n << '\n';
        else {
            cnt = 0;
            findfact(n, 10007);
            std::sort(a + 1, a + cnt + 1);
            for (int i = 1; i <= cnt; i++)
                std::cout << a[i] << ' ';
            std::cout << '\n';
        }
    }
    return 0;
}

long long power(long long a, long long b, long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = multi(ans, a, p);
        b >>= 1;
        a = multi(a, a, p);
    }
    return ans;
}

long long multi(long long a, long long b, long long p) {
    long long ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }
    return ans;
}

bool miller_rabin(long long n) {
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1))
        return false;
    long long m = n - 1;
    int k = 0;
    while (!(m & 1))
        k++, m >>= 1;
    for (int i = 1; i <= 10; i++) {
        long long a = rand() % (n - 1) + 1, y = 0;
        long long x = power(a, m, n);
        for (int j = 1; j <= k; j++) {
            y = multi(x, x, n);
            if (y == 1 && x != 1 && x != n - 1)
                return false;
            x = y;
        }
        if (y != 1)
            return false;
    }
    return true;
}

long long pollard_rho(long long n, int c) {
    long long x, y, d, i = 1, k = 2;
    x = rand() % (n - 1) + 1;
    y = x;
    while (true) {
        i++;
        x = (multi(x, x, n) + c) % n;
        d = gcd((y - x + n) % n, n);
        if (1 < d && d < n)
            return d;
        if (y == x)
            return n;
        if (i == k) {
            y = x;
            k <<= 1;
        }
    }
}

void findfact(long long n, int k) {
    if (n == 1)
        return;
    if (miller_rabin(n)) {
        a[++cnt] = n;
        return;
    }
    long long p = n;
    while (p >= n)
        p = pollard_rho(p, k--);
    findfact(p, k);
    findfact(n / p, k);
}
