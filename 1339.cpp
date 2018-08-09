// 1339.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

void dfs(int x, int y);

int m, n, cnt, ans = 0x3F3f3F3F;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char mat[21][21];
bool vi[21][21];

int main(int argc, const char * argv[]) {
    while(true) {
        memset(mat, '#', sizeof mat);
        memset(vi, false, sizeof vi);
        std::cin >> m >> n;
        if (!(m || n))
            break;
        int bx, by;
        ans = 0x3F3F3F3F;
        cnt = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                std::cin >> mat[i][j];
                if (mat[i][j] == '@') {
                    bx = i;
                    by = j;
                }
            }
        dfs(bx, by);
        std::cout << (ans == 0x3F3F3F3F ? -1 : ans) << '\n';
    }
    return 0;
}

void dfs(int x, int y) {
    if (mat[x][y] == '*') {
        ans = std::min(cnt, ans);
        return;
    }
    vi[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!vi[nx][ny] && (mat[nx][ny] == '.' || mat[nx][ny] == '*') && nx <= n && nx >= 1 && ny >= 1 && ny <= m) {
            dfs(nx, ny);
        }
    }
    vi[x][y] = false;
    cnt--;
}