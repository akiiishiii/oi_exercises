// road.cpp
#include <cstring>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("road.in");
std::ofstream out("road.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long const Mod = 2009;
long long n, T;
char s[15][15];

struct matrix {
    long long f[105][105];
    matrix() { memset(f, 0, sizeof(f)); }
    matrix operator*(matrix const &m) {
        matrix res;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    res.f[i][j] += f[i][k] * m.f[k][j], res.f[i][j] %= Mod;
        return res;
    }
} mat;

matrix mpow(matrix a, long long b) {
    matrix p;
    for (int i = 1; i <= n; i++)
        p.f[i][i] = 1;
    while (b) {
        if (b & 1)
            p = p * a;
        a = a * a, b >>= 1;
    }
    return p;
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    in >> n >> T;
    for (int i = 1; i <= n; i++)
        in >> (s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 8; j++)
            mat.f[(i - 1) * 9 + j][(i - 1) * 9 + j + 1] = 1;
        for (int j = 1; j <= n; j++)
            if (s[i][j] > '0')
                mat.f[(i - 1) * 9 + s[i][j] - '0'][(j - 1) * 9 + 1] = 1;
    }
    n *= 9;
    out << mpow(mat, T).f[1][n - 8] << '\n';
    return 0;
}