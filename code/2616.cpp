// 2616.cpp
#include <iostream>

int const dx[] = {0, 1, 0, -1, 0}, dy[] = {0, 0, 1, 0, -1};
int mat[41][41], r, c;
bool vis[41][41];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x = 1, y = 1;
    std::cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            std::cin >> mat[i][j];
    while (!(x == r && y == c)) {
        int pos;
        for (int i = 1, maxx = 0; i <= 4; i++) {
            if (mat[x + dx[i]][y + dy[i]] > maxx && x + dx[i] >= 1 &&
                x + dx[i] <= r && y + dy[i] >= 1 && y + dy[i] <= c &&
                !vis[x + dx[i]][y + dy[i]])
                pos = i, maxx = mat[x + dx[i]][y + dy[i]];
        }
        vis[x + dx[pos]][y + dy[pos]] = true;
        mat[x + dx[pos]][y + dy[pos]] += mat[x][y];
        x += dx[pos], y += dy[pos];
    }
    std::cout << mat[r][c] << '\n';
    return 0;
}