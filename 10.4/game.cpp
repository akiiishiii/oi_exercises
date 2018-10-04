// game.cpp
#include <iostream>
#include <fstream>
#include <cstring>

#define debug

#ifndef debug

std::ifstream in("game.in");
std::ofstream out("game.out");

#else

#define in std::cin
#define out std::cout

#endif // debug
/*
int score[1005] = {0};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n, m;
    int dice[7] = {0};
    in >> n >> m;
    for (int maxd = 0; maxd < m; maxd++) {
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
*/
int score[100005], tot[1005], dice[7];
int n, m, t;
int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int maxd, maxn;
    in >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        memset(dice, 0, sizeof(dice));
        maxn = 0;
        maxd = 7;
        for (int j = 1, x; j <= 6; j++) {
            in >> x;
            dice[x]++;
            if (dice[x] > maxn || (dice[x] == maxn && x < maxd)) {
                maxn = dice[x];
                maxd = x;
            }
            score[i] = dice[maxd];
            if (maxd == 1 || maxd == 4)
                score[i] *= 2;
        }
    }
    t = 1, maxn = 0, maxd = n + 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            tot[t] += score[n * (i - 1) + j];
            if (tot[t] > maxn || (tot[t] == maxn && t < maxd)) {
                maxn = tot[t];
                maxd = t;
            }
            t++;
            if (t > n)
                t = 1;
        }
        t = maxd;
    }
    out << maxd << ' ' << maxn << '\n';
    return 0;
}