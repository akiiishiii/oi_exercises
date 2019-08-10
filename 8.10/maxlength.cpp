// maxlength.cpp
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("maxlength.in");
std::ofstream out("maxlength.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
int n, m, T, ans, cnt, d[31][31];
bool map[31][31];

void dfs(int x, int y, int num, int sum);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    in >> n >> m >> T;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char c;
            in >> c;
            if (c == '\n') {
                j--;
                continue;
            }
            if (c == '1')
                cnt++;
            map[i][j] = c - '0';
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            for (int x = 1; x <= n; ++x)
                for (int y = 1; y <= m; ++y)
                    d[x][y] = 2147483647;
            dfs(i, j, map[i][j], cnt);
            for (int x = 1; x <= n; ++x)
                for (int y = 1; y <= m; ++y)
                    if (d[x][y] <= T)
                        ans = std::max(ans,
                                       (x - i) * (x - i) + (y - j) * (y - j));
        }
    std::cout << std::fixed << std::setprecision(6) << sqrt(ans) << '\n';
    return 0;
}

void dfs(int x, int y, int num, int sum) {
    if (cnt - num < sum)
        return; //
    if (num > T)
        return;
    if (num >= d[x][y])
        return;
    d[x][y] = num;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            dfs(nx, ny, num + map[nx][ny], sum - map[nx][ny]);
    }
}