#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
#define LL unsigned long long

const int Times = 10;
const LL INF = (LL)1 << 61;
const int N = 550;

LL n, m, ct, cnt, mini, mina, minb, ans;
LL fac[N], num[N];

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

LL multi(LL a, LL b, LL m) {
    LL ans = 0;
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

LL quick_mod(LL a, LL b, LL m) {
    LL ans = 1;
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

bool Miller_Rabin(LL n) {
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1))
        return false;
    LL a, m = n - 1, x, y;
    int k = 0;
    while ((m & 1) == 0) {
        k++;
        m >>= 1;
    }
    for (int i = 0; i < Times; i++) {
        a = rand() % (n - 1) + 1;
        x = quick_mod(a, m, n);
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

LL Pollard_rho(LL n, LL c) {
    LL x, y, d, i = 1, k = 2;
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

void find(LL n, int c) {
    if (n == 1)
        return;
    if (Miller_Rabin(n)) {
        fac[ct++] = n;
        return;
    }
    LL p = n;
    LL k = c;
    while (p >= n)
        p = Pollard_rho(p, c--);
    find(p, k);
    find(n / p, k);
}

void dfs(LL c, LL value) {
    LL s = 1, a, b;
    if (c == cnt) {
        a = value;
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
    for (LL i = 0; i <= num[c]; i++) {
        if (s * value > mini)
            return;
        dfs(c + 1, s * value);
        s *= fac[c];
    }
}

int main() {
    while (~scanf("%llu%llu", &n, &m)) {
        if (n == m) {
            printf("%llu %llu\n", n, m);
            continue;
        }
        mini = INF;
        ct = cnt = 0;
        ans = m / n;
        find(ans, 120);
        sort(fac, fac + ct);
        num[0] = 1;
        int k = 1;
        for (LL i = 1; i < ct; i++) {
            if (fac[i] == fac[i - 1])
                ++num[k - 1];
            else {
                num[k] = 1;
                fac[k++] = fac[i];
            }
        }
        cnt = k;
        dfs(0, 1);
        if (mina > minb)
            swap(mina, minb);
        printf("%llu %llu\n", mina, minb);
    }
    return 0;
}