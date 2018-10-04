// gold.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#define debug

#ifndef debug

std::ifstream in("gold.in");
std::ofstream out("gold.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long d[210][210], f[210][4100];
long long minpath = 0x3f3f3f3f3f3f3f3f;
int n, m, p;
int gold[13] = {0};

void dfs(int status, int pos, long long path);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    memset(d, 0x3f, sizeof(d));
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        long long z;
        in >> x >> y >> z;
        d[x][y] = d[y][x] = std::min(d[x][y], z);
    }
    in >> p;
    for (int i = 1; i <= p; i++)
        in >> gold[i];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    if (d[1][n] == 0x3f3f3f3f3f3f3f3f) {
        out << "-1\n";
        return 0;
    }
    for (int i = 1; i <= p; i++)
        if (d[1][gold[i]] == 0x3f3f3f3f3f3f3f3f) {
            out << "-1\n";
            return 0;
        }
        dfs(0, 1, 0);
    out << (minpath == 0x3f3f3f3f3f3f3f3f ? (-1) : minpath) << '\n';
    return 0;
}

void dfs(int status, int pos, long long path) {
    if (path < f[pos][status])
        f[pos][status] = path;
    else
        return;
    if (status == (1 << p) - 1) {
        minpath = std::min(minpath, path + d[pos][n]);
        return;
    }
    for (int i = 1; i <= p; i++)
        if (!(status & (1 << (i - 1))))
            dfs(status | (1 << (i - 1)), gold[i], path + d[pos][gold[i]]);
}