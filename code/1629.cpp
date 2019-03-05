// 1629.cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

long long n, m, tot, cnt, mini, mina, minb, ans;
long long facts[550], num[550];

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long multi(long long a, long long b, long long m);
long long power(long long a, long long b, long long m);
bool miller_Rabin(long long n);
long long pollard_rho(long long n, long long c);
void findfact(long long n, int c);
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
        tot = cnt = 0;
        ans = m / n;
        findfact(ans, 120);
        std::sort(facts, facts + tot);
        num[0] = 1;
        int k = 1;
        for (long long i = 1; i < tot; i++) {
            if (facts[i] == facts[i - 1])
                ++num[k - 1];
            else {
                num[k] = 1;
                facts[k++] = facts[i];
            }
        }
        cnt = k;
        dfs(0, 1);
        if (mina > minb)
            std::swap(mina, minb);
        std::cout << mina << ' ' << minb << '\n';
    }
    return 0;
}

long long multi(long long a, long long b, long long m) {
    long long ans = 0;
    while (b) {
        if (b & 1) {
            ans = (ans + a) % m;
            b--;
        }
        b >>= 1;
        a = (a + a) % m;
    }
    return ans;
}

long long power(long long a, long long b, long long m) {
    long long ans = 1;
    a %= m;
    while (b) {
        if (b & 1) {
            ans = multi(ans, a, m);
            b--;
        }
        b >>= 1;
        a = multi(a, a, m);
    }
    return ans;
}

bool miller_Rabin(long long n) {
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1))
        return false;
    long long a, m = n - 1, x, y;
    int k = 0;
    while ((m & 1) == 0) {
        k++;
        m >>= 1;
    }
    for (int i = 0; i < 10; i++) {
        a = rand() % (n - 1) + 1;
        x = power(a, m, n);
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

long long pollard_rho(long long n, long long c) {
    long long x, y, d, i = 1, k = 2;
    y = x = rand() % (n - 1) + 1;
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

void findfact(long long n, int c) {
    if (n == 1)
        return;
    if (miller_Rabin(n)) {
        facts[tot++] = n;
        return;
    }
    long long p = n;
    long long k = c;
    while (p >= n)
        p = pollard_rho(p, c--);
    findfact(p, k);
    findfact(n / p, k);
}

void dfs(long long c, long long k) {
    long long s = 1, a, b;
    if (c == cnt) {
        a = k;
        b = ans / a;
        if (gcd(a, b) == 1) {
            a *= n;
            b *= n;
            if (a + b < mini) {
                mini = a + b;
                mina = a;
                minb = b;
            }
        }
        return;
    }
    for (long long i = 0; i <= num[c]; i++) {
        if (s * k > mini)
            return;
        dfs(c + 1, s * k);
        s *= facts[c];
    }
}