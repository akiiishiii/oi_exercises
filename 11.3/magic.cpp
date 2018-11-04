// magic.cpp
#include <iostream>
#include <fstream>
#include <cstring>

//#define debug

#ifndef debug

std::ifstream in("magic.in");
std::ofstream out("magic.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int matrix[40][40];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    memset(matrix, 0, sizeof(matrix));
    int n;
    in >> n;
    matrix[1][(n + 1) >> 1] = 1;
    for(int i = 2, row = 1, col = (n + 1) >> 1; i <= n * n; i++)
        if((i - 1) % n == 0)
            matrix[++row][col] = i;
        else if(row == 1)
            matrix[row = n][++col] = i;
        else if(col == n)
            matrix[--row][col = 1] = i;
        else
            matrix[--row][++col] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            out << matrix[i][j] << ' ';
        out << '\n';
    }
    return 0;
}