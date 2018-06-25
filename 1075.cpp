#include <iostream>

int main(int argc, const char * argv[]) {
    int m, n, k, a[16][16], b[16][16], product[16][16] = {0};
    std::cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            std::cin >> b[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= k; j++)
            for (int l = 1; l <= n; l++)
                product[i][j] += a[i][l] * b[l][j];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++)
            std::cout << product[i][j];
        std::cout << std::endl;
    }
    return 0;
}
