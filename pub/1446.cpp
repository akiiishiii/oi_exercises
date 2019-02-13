// 1446.cpp
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
int col[9] = {0}, row[9] = {0}, box[9] = {0}, map[9][9], put[9] = {0};

void dfs(int x, int y);

int main(int argc, char const *argv[]) {
    memset(map, 0, sizeof(map));
    char c;
    int maxi = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            std::cin >> c;
            if (c != '?') {
                col[i] |= 1 << (c - '0');
                row[j] |= 1 << (c - '0');
                box[B[i][j]] |= 1 << (c - '0');
                map[i][j] = c - '0';
                put[i]++;
            }
        }
    for (int i = 0; i < 9; i++)
        maxi = put[maxi] > put[i] ? maxi : i;
    for (int i = 0; i < 9; i++)
        
    return 0;
}

void dfs(int x, int y) {
    
}
