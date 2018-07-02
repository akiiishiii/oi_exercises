// 1356.cpp
#include <iostream>

const int SIZE = 300;
int matrix[SIZE + 1][SIZE + 1];
int rowsum[SIZE + 1][SIZE + 1];
int n, i, j, first, last, area, ans;

int main(int argc, const char * argv[]) {
    std::cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            std::cin >> matrix[i][j];
    ans = matrix[1][1];
    for (i = 1; i <= n; i++)
        rowsum[i][0] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            rowsum[i][j] = rowsum[i][j - 1] + matrix[i][j];
    for (first = 1; first <= n; first++)
        for (last = first; last <= n; last++) {
            area = 0;
            for (i = 1; i <= n; i++) {
                area += rowsum[i][last] - rowsum[i][first - 1];
                if (area > ans)
                    ans = area;
                if (area < 0)
                    area = 0;
            }
        }
    std::cout << ans << std::endl;
    return 0;
}