// 1293.cpp
#include <cmath>
#include <cstring>
#include <iostream>

int const Maxn = 729;
char mat[Maxn][Maxn];

void build(int k, int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    while ((std::cin >> n) && (n != -1)) {
        memset(mat, ' ', sizeof mat);
        build(n, 0, 0);
        int size = pow(3, n - 1);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                std::cout << mat[i][j];
            std::cout << '\n';
        }
        std::cout << "-\n";
    }
    return 0;
}

void build(int k, int x, int y) {
    if (k == 1) {
        mat[x][y] = 'X';
        return;
    }
    int size = pow(3, k - 2);
    build(k - 1, x, y);
    build(k - 1, x + 2 * size, y);
    build(k - 1, x + 2 * size, y + 2 * size);
    build(k - 1, x, y + 2 * size);
    build(k - 1, x + size, y + size);
    return;
}