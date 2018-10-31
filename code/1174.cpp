// 1174.cpp
#include <iostream>
#include <iomanip>

double f[1010][1010], p[1010][1010][3];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int r, c;
    while (std::cin >> r >> c) {
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                for (int k = 0; k < 3; k++)
                    std::cin >> p[i][j][k];
        f[r][c] = 0;
        for (int i = r; i > 0; i--)
            for (int j = c; j > 0; j--)
                if (p[i][j][0] != 1 && (i != r || j != c))
                    f[i][j] = (f[i][j + 1] * p[i][j][1] + f[i + 1][j] * p[i][j][2] + 2) / (1 - p[i][j][0]);
        std::cout << std::fixed << std::setprecision(3) << f[1][1] << '\n';
    }
    return 0;
}
