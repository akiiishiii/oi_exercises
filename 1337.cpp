// 1329.cpp
#include <iostream>
#include <cstring>

void dfs(int x, int y);

int m, n, cnt;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
char mat[115][115];
bool vi[115][115];

int main(int argc, const char * argv[]) {
    memset(mat, 0, sizeof(mat));
    memset(vi, false, sizeof(vi));
    std::cin >> n >> m;
    int bx, by;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mat[i][j] != '.' && !vi[i][j]) {
                cnt++;
                bx = i;
                by = j;
                dfs(bx, by);
            }
    std::cout << cnt << std::endl;
    return 0;
}

void dfs(int x, int y) {
    vi[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!vi[nx][ny] && mat[nx][ny] != '.' && nx <= n && nx >= 1 && ny >= 1 && ny <= m)
            dfs(nx, ny);
    }
}