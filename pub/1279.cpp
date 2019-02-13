// 1279.cpp
#include <iostream>
#include <cstring>

void dfs(int x, int y);

int w, h, cnt;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char mat[21][21];
bool vi[21][21];

int main(int argc, const char * argv[]) {
    while(true) {
        memset(mat, '#', sizeof mat);
        memset(vi, false, sizeof vi);
        std::cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        int bx, by;
        cnt = 0;
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++) {
                std::cin >> mat[i][j];
                if (mat[i][j] == '@') {
                    bx = i;
                    by = j;
                }
            }
        dfs(bx, by);
        std::cout << cnt << std::endl;
    }
    return 0;
}

void dfs(int x, int y) {
    vi[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!vi[nx][ny] && mat[nx][ny] == '.' && nx <= h && nx >= 1 && ny >= 1 && ny <= w)
            dfs(nx, ny);
    }
}