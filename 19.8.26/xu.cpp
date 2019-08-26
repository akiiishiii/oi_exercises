// xu.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("xu.in");
std::ofstream out("xu.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Mod = 1000000007, Maxn = 210000;
int n, m, t, p;
int fact[Maxn], inv[Maxn];

inline void pre();
inline int c(int n, int m);
int power(int a, int b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> t >> p;
    p = std::abs(p);
    if (t < p) {
        out << "0\n";
    } else {
        pre();
        out << (long long)c(2 * t, (2 * t - 2 * p) / 2) *
                   power(power(2, 2 * t), Mod - 2) % Mod
            << '\n';
    }
    return 0;
}

inline void pre() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= 2 * t; i++)
        fact[i] = (long long)fact[i - 1] * i % Mod;
    inv[2 * t] = power(fact[2 * t], Mod - 2);
    for (int i = 2 * t - 1; i >= 1; i--)
        inv[i] = (long long)inv[i + 1] * (i + 1) % Mod;
}

inline int c(int n, int m) {
    return (long long)fact[n] * inv[m] % Mod * inv[n - m] % Mod;
}

int power(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = (long long)ret % Mod * a % Mod;
        a = (long long)a * a % Mod;
        b = b / 2;
    }
    return ret % Mod;
}