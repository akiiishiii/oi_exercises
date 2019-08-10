// game.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("game.in");
std::ofstream out("game.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int pri[1005];
bool vis[1005];
long long f[205][1005];
int tot, n;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    for (int i = 2; i <= 1000; i++) {
        if (!vis[i])
            pri[++tot] = i;
        for (int j = 1; j <= tot && i * pri[j] <= 1000; ++j) {
            vis[i * pri[j]] = true;
            if (i % pri[j] == 0)
                break;
        }
    }
    for (int i = 0; i <= tot; i++)
        f[i][0] = 1;
    for (int i = 1; i <= n; i++)
        f[0][i] = 1;
    for (int i = 1; i <= tot; i++)
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            for (int k = pri[i]; k <= j; k *= pri[i])
                f[i][j] += f[i - 1][j - k];
        }
    out << f[tot][n] << '\n';
    return 0;
}