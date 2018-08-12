// 1608.cpp
#include <iostream>
#include <cstring>

int const B[9][9] = {
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {6, 6, 6, 7, 7, 7, 8, 8, 8},
    {6, 6, 6, 7, 7, 7, 8, 8, 8},
    {6, 6, 6, 7, 7, 7, 8, 8, 8}
};
int col[9] = {0}, row[9] = {0}, box[9] = {0}, map[9][9];

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        memset(map, 0, sizeof(map));
        memset(col, 0, sizeof(col));
        memset(row, 0, sizeof(row));
        memset(box, 0, sizeof(box));
        for (int i = 0; i < 9 && flag; i++)
            for (int j = 0; j < 9 && flag; j++) {
                std::cin >> map[i][j];
                if ((col[i] >> map[i][j] & 1) || (row[j] >> map[i][j] & 1) || (box[B[i][j]] >> map[i][j] & 1)) {
                    std::cout << "Wrong\n";
                    flag = false;
                    break;
                }
                col[i] |= 1 << map[i][j];
                row[j] |= 1 << map[i][j];
                box[B[i][j]] |= 1 << map[i][j];
            }
        if (flag)
            std::cout << "Right\n";
    }
    return 0;
}
