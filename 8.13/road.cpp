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

int dis[55][55], n, m;
bool mat[55][55][65];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    memset(mat, false, sizeof(mat));
    memset(dis, 0x3f, sizeof(dis));
    in >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        in >> x >> y;
        dis[x][y] = 1;
        mat[x][y][0] = true;
    }
    for (int k = 1; k <= 64; k++)
        for (int i = 1; i <= n; i++)
            for (int t = 1; t <= n; t++)
                for (int j = 1; j <= n; j++)
                    if (mat[i][t][k - 1] && mat[t][j][k - 1]) {
                        mat[i][j][k] = true;
                        dis[i][j] = 1;
                    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
    out << dis[1][n] << '\n';
    return 0;
}
