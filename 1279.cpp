// 1279.cpp
#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    while(true) {
        int w, h;
        char mat[21][21];
        memset(mat, '#', sizeof(mat));
        std::cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                std::cin >> mat[i][j];

    }
    return 0;
}