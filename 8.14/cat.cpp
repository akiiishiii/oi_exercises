// cat.cpp
#include <cmath>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug2

std::ifstream in("cat.in");
std::ofstream out("cat.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long s[4001] = {0};

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long sqr(int x) { return s[x] - s[x - 1]; }
inline bool chk(long long x, long long y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    long long T, a;
    long long tot, stom, sjerry;
    for (long long i = 1; i <= 4000; i++)
        s[i] = (long long)i * (i + 1) * (2 * i + 1) / 6;
    in >> T;
    while (T--) {
        tot = stom = sjerry = 0;
        in >> a;
        for (long long i = 2; i <= 2 * a; i++)
            if (chk(a, i)) {
                for (long long j = std::max(1ll, i - a);
                     j <= std::min(a, i / 2); j++) {
                    stom += sqr(a) + sqr(i);
                    tot++;
                    sjerry += sqr(a) + sqr(j) + sqr(i - j);
                }
            }
        if (!tot)
            out << "NULL/NULL NULL/NULL\n";
        else {
            long long gt = gcd(tot, stom), gj = gcd(tot, sjerry);
            out << stom / gt << '/' << tot / gt << ' ' << sjerry / gj << '/'
                << tot / gj << '\n';
        }
    }
    return 0;
}

inline bool chk(long long x, long long y) {
    long long z = sqrt(sqr(x) + sqr(y));
    return sqr(z) == sqr(x) + sqr(y);
}