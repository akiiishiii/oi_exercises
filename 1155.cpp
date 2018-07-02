// 1155.cpp
#include <iostream>
#include <cstring>

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int main(int argc, const char * argv[]) {
    char map[102][102];
    int num[102][105];
    int m, n;
    memset(map, '#', sizeof(map));
    memset(num, 0, sizeof(num));
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> map[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (map[i][j] == '*')
                std::cout << '*';
            else if (map[i][j] == '?') {
                int res = 0;
                for (int k = 0; k < 8; k++)
                    if (map[i + dx[k]][j + dy[k]] == '*')
                        res++;
                std::cout << res;
            } else
                continue;
        std::cout << std::endl;
    }
    return 0;
}