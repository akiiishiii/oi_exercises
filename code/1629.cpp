// 1629.cpp
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

long long n, m, ans, tot = 0, cnt = 0, mini, mina, minb, a[550], num[550];

long long gcd(long long a, long long b) { return a % b ? gcd(b, a % b) : b; }
long long multi(long long a, long long b, long long mod);
bool miller_rabin(long long n);
long long power(long long a, long long b, long long p);
long long pollard_rho(long long n, int c);
void findfact(long long n, int k);
void dfs(long long c, long long k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    srand((unsigned)time(NULL));
    while (std::cin >> n >> m) {
        if (n == m) {
            std::cout << n << ' ' << m << '\n';
            continue;
        }
        mini = 1ll << 61;
        cnt = tot = 0;
        ans = m / n;
        findfact(ans, 120);
        std::sort(a, a + cnt);
        num[0] = 1;
        int k = 1;
        for (long long i = 1; i < cnt; i++) {
            if (a[i] == a[i - 1])
                ++num[k - 1];
            else {
                num[k] = 1;
                a[k++] = a[i];
            }
        }
        tot = k;
        dfs(0, 1);
        if (mina > minb)
            std::swap(mina, minb);
        std::cout << mina << ' ' << minb << '\n';
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
        for (int j = 0; j < k; j++) {
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
        a[cnt++] = n;
        if (n < ans)
            ans = n;
        return;
    }
    long long p = n;
    while (p >= n)
        p = pollard_rho(p, k--);
    findfact(p, k);
    findfact(n / p, k);
}

void dfs(long long t, long long k) {
    long long s = 1, x, y;
    if (t == tot) {
        x = k;
        y = ans / x;
        if (gcd(x, y) == 1) {
            x *= n, y *= n;
            if (x + y < mini) {
                mini = x + y;
                mina = x, minb = y;
            }
        }
        return;
    }
    for (long long i = 0; i <= num[t]; i++) {
        if (s * k > mini)
            return;
        dfs(t + 1, s * k);
        s *= a[t];
    }
}