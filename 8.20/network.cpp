// network.cpp
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("network.in");
std::ofstream out("network.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m, x, y, a[110][110], z;
long long p[110][110];
double ans[110] = {0.0};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    memset(a, 10, sizeof(a));
    memset(p, 0, sizeof(p));
    in >> n >> m;
    for (int i = 1; i <= m; i++) {
        in >> x >> y >> z;
        a[x][y] = a[y][x] = z;
        p[x][y] = p[y][x] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    p[i][j] = p[i][k] * p[k][j];
                } else if (a[i][k] + a[k][j] == a[i][j])
                    p[i][j] += p[i][k] * p[k][j];
            }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && j != k && k != i)
                    if (a[i][k] + a[k][j] == a[i][j])
                        ans[k] += (double)p[i][k] * p[k][j] / p[i][j];
    for (int i = 1; i <= n; i++)
        out << std::fixed << std::setprecision(3) << ans[i] << '\n';
    return 0;
}