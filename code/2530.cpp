// 2530.cpp
#include <iostream>
#include <cstring>

int my[1005] = {0};
bool map[1005][1005], mapin[1005][1005], vst[1005] = {false};
int num[1005][1005][2];
int r, c, x, y;

bool dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> r >> c;
    char ch;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            std::cin >> ch, mapin[i][j] = (ch == '*');
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (mapin[i][j])
                num[i][j][0] = (mapin[i][j - 1] ? x : ++x);
    for (int j = 1; j <= c; j++)
        for (int i = 1; i <= r; i++)
            if (mapin[i][j])
                num[i][j][1] = (mapin[i - 1][j] ? y : ++y);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (mapin[i][j])
                map[num[i][j][0]][num[i][j][1]] = true;
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        memset(vst, false, sizeof(vst));
        if (dfs(i))
            ans++;
    }
    std::cout << ans << '\r';
    return 0;
}

bool dfs(int x) {
    for (int i = 1; i <= y; i++)
        if (!vst[i] && map[x][i]) {
            vst[i] = true;
            if (!my[i] || dfs(my[i])) {
                my[i] = x;
                return true;
            }
        }
    return false;
}