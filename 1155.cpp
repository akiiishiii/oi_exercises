// 1155.cpp
#include <iostream>
#include <cstring>

char check(char ** m, int a, int b);

int main(int argc, const char * argv[]) {
    char map[102][102];
    int m, n;
    memset(map, '0', sizeof(map));
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> map[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cout << check(map, i, j);
    return 0;
}

char check(char ** m, int a, int b) {
    if (m[a][b] == '*')
        return '*';
    else {
        int res
    }
}