#include <iostream>
#include <cstring>

int main(int argc, char const *argv[]) {
    int n[21][21];
    memset(n, 0, sizeof(n));
    for (int i = 1; i <= 20; i++)
        n[i][1] = n[i][i] = 1;
    for (int i = 2; i <= 20; i++)
        for (int j = 2; j < i; j++)
            n[i][j] = n[i - 1][j - 1] + n[i - 1][j];
    std::cout << "{\n";
    for (int i = 1; i <= 20; i++) {
        std::cout << '{';
        for (int j = 1; j <= 19; j++)
            std::cout << n[i][j] << ", ";
        std::cout << n[i][20] << "},\n";
    }
    std::cout << "}\n";
        return 0;
}
