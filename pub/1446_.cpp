// 1446_.cpp
#include<iostream>
#include<cstring>

int lastx, mat[12][12], col[12], row[12], box[12][12];

bool dfs(int tot);

int main(int argc, char const *argv[]) {
    lastx = 1;
    memset(mat, 0, sizeof mat);
    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);
    memset(box, 0, sizeof box);
    int tot = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            char tmp;
            std::cin >> tmp;
            mat[i][j] = tmp == '?' ? 0 : tmp - '0';
            if (!mat[i][j])
                tot++;
            if (mat[i][j]) {
                col[i] |= 1 << mat[i][j];
                row[j] |= 1 << mat[i][j];
            }
        }
    }
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int k1 = (i - 1) * 3 + 1; k1 <= i * 3; k1++)
                for (int k2 = (j - 1) * 3 + 1; k2 <= j * 3; k2++)
                    if (mat[k1][k2])
                        box[i][j] |= 1 << mat[k1][k2];
    dfs(tot);
    return 0;
}

bool dfs(int tot) {
    if(!tot){
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++)
                std::cout << mat[i][j];
            std::cout << '\n';
        }
        return true;
    }
    for (int i = lastx; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (mat[i][j])
                continue;
            int ra = col[i], rb = row[j], x = (i - 1) / 3 + 1, y = (j - 1) / 3 + 1, rc = box[x][y], rd = ra | rb | rc, p = lastx;
            for (int k = 1; k <= 9; k++) {
                if (!(rd & (1 << k))) {
                    mat[i][j] = k;
                    col[i] |= 1 << k;
                    row[j] |= 1 << k;
                    box[x][y] |= 1 << k;
                    lastx = i;
                    if (dfs(tot - 1))
                        return true;
                    mat[i][j] = 0;
                    lastx = p;
                    col[i] ^= 1 << k;
                    row[j] ^= 1 << k;
                    box[x][y] ^= 1 << k;
                }
            }
            return false;
        }
    }
    return false;
}
