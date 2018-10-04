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

int score[1005] = {0};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n, m;
    int dice[7];
    in >> n >> m;
    for (int k = 0; k < m; k++) {
        for (int i = 1; i <= n; i++) {
            dice[1] = dice[2] = dice[3] = dice[4] = dice[5] = dice[6] = 0;
            for (int j = 0, tmp; j < 6; j++) {
                in >> tmp;
                dice[tmp]++;
            }
            int maxn = 0;
            for (int j = 1; j <= 6; j++)
                maxn = dice[maxn] < dice[j] ? j : maxn;
            score[i] += (dice[maxn] * ((maxn == 1 || maxn == 4) ? 2 : 1));
        }
    }
    int maxn = 0;
    for (int i = n; i > 0; i--)
        maxn = score[maxn] <= score[i] ? i : maxn;
    out << maxn << ' ' << score[maxn] << '\n';
    return 0;
}