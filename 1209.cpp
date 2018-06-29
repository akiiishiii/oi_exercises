// 1209.cpp
#include <iostream>

long long map[21][21];

int main(int argc, const char * argv[]) {
    int i, j, n, m, a, b;
    std::cin >> n >> m >> a >> b;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++)
            map[i][j] = 1;
    if (a - 2 >= 0 && b - 1 >= 0)
        map[a - 2][b - 1] = 0;
    if (a - 2 >= 0 && b + 1 <= m)
        map[a - 2][b + 1] = 0;
    if (a - 1 >= 0 && b - 2 >= 0)
        map[a - 1][b - 2] = 0;
    if (a - 1 >= 0 && b + 2 <= m)
        map[a - 1][b + 2] = 0;
    if (a + 1 <= m && b - 2 >= 0)
        map[a + 1][b - 2] = 0;
    if (a + 2 <= n && b - 1 >= 0)
        map[a + 2][b - 1] = 0;
    if (a + 1 <= n && b + 2 <= m)
        map[a + 1][b + 2] = 0;
    if (a + 1 <= n && b + 1 <= m)
        map[a + 2][b + 1] = 0;
    map[a][b] = 0;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (map[i][j]) {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    map[i][j] = map[i][j - 1];
                else if (j == 0)
                    map[i][j] = map[i - 1][j];
                else
                    map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
    }
    std::cout << map[n][m] << std::endl;
    return 0;
}