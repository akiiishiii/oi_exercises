// 3318.cpp
#include <iostream>

long long n, g, fact[35617 + 5], mods[5];
long long const Mod = 999911658, facts[] = {0, 2, 4679, 35617};

void exgcd(long long a, long long b, long long &x, long long &y);
long long inv(long long a, long long p);
long long power(long long x, long long b, long long p);
long long calc(long long i, long long p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> g;
    if (!(g % (Mod + 1ll))) {
        std::cout << "0\n";
        return 0;
    }
    fact[0] = 1;
    for (long long i = 1ll; i <= 35617ll; i++)
        fact[i] = fact[i - 1] * i % Mod;
    for (long long i = 1ll; i * i <= n; i++) {
        if (n % i == 0ll) {
            for (long long j = 1ll; j <= 4ll; j++)
                mods[j] = (mods[j] + calc(i, facts[j])) % facts[j];
            if (i * i != n)
                for (long long j = 1ll; j <= 4ll; j++)
                    mods[j] = (mods[j] + calc(n / i, facts[j])) % facts[j];
        }
    }
    long long x, y, b = 0;
    for (long long i = 1ll; i <= 4ll; i++) {
        exgcd(Mod / facts[i], facts[i], x, y);
        b = (b + mods[i] % Mod * (Mod / facts[i]) % Mod * x % Mod) % Mod;
    }
    b = (b % Mod + Mod) % Mod;
    std::cout << power(g, b, Mod + 1ll) << '\n';
    return 0;
}

void exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1ll, y = 0ll;
        return;
    }
    exgcd(b, a % b, x, y);
    long long d = x;
    x = y, y = d - (a / b) * y;
}

long long inv(long long a, long long p) {
    long long x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

long long power(long long x, long long b, long long p) {
    long long ret = 1ll;
    while (b) {
        if (b & 1)
            ret = ret * x % p;
        x = x * x % p;
        b >>= 1;
    }
    return ret;
}

long long calc(long long i, long long p) {
    long long ret = 1ll, x, y, nn, mm;
    for (x = n, y = i; y; x /= p, y /= p) {
        nn = x % p, mm = y % p;
        ret = ret * fact[nn] % p * inv(fact[mm], p) % p *
              inv(nn < mm ? 0 : fact[nn - mm], p) % p;
    }
    return ret;
}