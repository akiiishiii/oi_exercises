// gold.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
//#include <queue>

//#define debug

#ifndef debug

std::ifstream in("gold.in");
std::ofstream out("gold.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long d[310][310];
long long minpath = 0x3f3f3f3f3f3f3f3f;
int n, m, p;
int gold[13] = {0};
bool v[13] = {false};

void dfs(int depth, int pos, long long path);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        long long z;
        in >> x >> y >> z;
        d[x][y] = d[y][x] = std::min(d[x][y], z);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    in >> p;
    for (int i = 1; i <= p; i++)
        in >> gold[i];
    dfs(0, 1, 0);
    out << (minpath == 0x3f3f3f3f3f3f3f3f ? (-1) : minpath) << '\n';
    return 0;
}

void dfs(int depth, int pos, long long path) {
    if (depth >= p) {
        minpath = std::min(minpath, path + d[pos][n]);
        return;
    }
    if (path >= minpath)
        return;
    for (int i = 1; i <= p; i++)
        if (!v[i]) {
            v[i] = true;
            dfs(depth + 1, gold[i], path + d[pos][gold[i]]);
            v[i] = false;
        }
}