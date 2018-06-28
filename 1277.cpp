// 1277.cpp
#include <iostream>

int r, s, ans = 0;
char mat[21][21];
bool vis[26] = {false};
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int _r, int _c, int _s);

int main(int argc, const char * argv[]) {
    std::cin >> r >> s;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= s; j++)
            std::cin >> mat[i][j];
    vis[mat[1][1] - 'A'] = true;
    dfs(1, 1, 1);
    std::cout << ans << std::endl;
    return 0;
}

void dfs(int _r, int _c, int _s) {
    ans = _s > ans ? _s : ans;
    for (int i = 0; i < 4; i++) {
        int x = _r + dx[i];
        int y = _c + dy[i];
        if (x > 0 && x <= r && y > 0 && y <= s && !vis[mat[x][y] - 'A']) {
            vis[mat[x][y] - 'A'] = true;
            dfs(x, y, s + 1);
            vis[mat[x][y] - 'A'] = false;
        }
    }
}