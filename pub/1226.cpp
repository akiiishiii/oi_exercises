// 1226.cpp
#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    long long t, n, m, x1, y1, x2, y2, map[31][31];
    memset(map, 0, sizeof(map));
    std::cin >> t >> m >> n;
    map[1][1] = 1;
    if (t == 1) {
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (i == 1 && j == 1)
                    continue;
                else
                    map[i][j] = map[i - 1][j] + map[i][j - 1];
    } else {
        std::cin >> x1 >> y1 >> x2 >> y2;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if ((i == 1 && j == 1) || (((i <= y1 && i >= y2) || (i >= y1 && i <= y2)) && ((j <= x1 && j >= x2) || (j >= x1 && j <= x2))))
                    continue;
                else
                    map[i][j] = map[i - 1][j] + map[i][j - 1];
    }
    std::cout << map[m][n] << std::endl;
    return 0;
}