// shiawase.cpp
#include <cmath>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("shiawase.in");
std::ofstream out("shiawase.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long d, n;
long long f[205][205], c[405][405];
long long const Mod = 1000000007;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> d >> n;
    for (int i = 0; i <= 400; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Mod;
    }
    for (int i = 0; i <= d; i++)
        f[i][0] = 1;
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 0; k <= j; k++)
                f[i][j] += (f[i - 1][j - k] * c[2 * j][2 * k] % Mod *
                            c[2 * k][k] % Mod) %
                           Mod;
    out << f[d][n] % Mod << '\n';
    return 0;
}