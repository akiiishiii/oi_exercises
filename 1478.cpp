// 1478.cpp
#include <iostream>

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m, h, i, j, a[65][65];
    std::cin >> n;
    m = 1;
    a[1][1] = 1;
    h = 1;
    for (i = 1; i <= n; i++)
        m = m * 2;
    while (h <= m) {
        for (i = 1; i <= h; i++)
            for (j = 1; j <= h; j++) {
                a[i][j + h] = a[i][j] + h;
                a[i + h][j] = a[i][j + h];
                a[i + h][j + h] = a[i][j];
            }
        h = h * 2;
    }
    for (i = 2; i <= m; i++) {
        for (j = 1; j <= m; j++)
            if (a[i][j] > j)
                std::cout << j << '-' << a[i][j] << " ";
        std::cout << '\n';
    }
    return 0;
}


