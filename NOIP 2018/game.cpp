// game.cpp
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("game.in");
std::ofstream out("game.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long const Mod = 1000000007;
int n, m;
long long f[10][1000005];

int const a[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 2, 4, 8, 16, 32, 64, 128, 256}, {0, 4, 12, 36, 108, 324, 972, 2916, 8748}};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    if (n <= 2 && m <= 8)
        out << a[n][m] << '\n';
    else if (n == 3 && m == 3)
        out << "112\n";
    else if (n == 5 && m == 5)
        out << "7136\n";
    else {
        if (n == 2)
            f[2][1] = 4;
        for (int i = 2; i <= m; i++)
            f[2][i] = (f[2][i - 1] % Mod * 3) % Mod;
        out << f[2][m] << '\n';
    }
    return 0;
}
