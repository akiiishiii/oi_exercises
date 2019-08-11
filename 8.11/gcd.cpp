// gcd.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("gcd.in");
std::ofstream out("gcd.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int f[1000005] = {0};

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int t, n, sum;
    in >> t;
    while (t--) {
        in >> n;
        if (!f[n]) {
            sum = 0;
            for (int i = 1; i <= n - 1; i++)
                for (int j = i + 1; j <= n; j++)
                    sum += gcd(i, j);
            out << (f[n] = sum) << '\n';
        } else
            out << f[n] << '\n';
    }
    return 0;
}