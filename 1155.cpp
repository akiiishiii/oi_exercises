// 1155.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int map[101][101], m, n;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> map[i][j];

    return 0;
}