// 1609.cpp Dancing Links 参考自互联网
#include<iostream>

const int MAXR = 9 * 9 * 9 + 10, MAXC = 9 * 9 * 4 + 10, score[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,6,6,6,6,6,6,6,6,6},
    {0,6,7,7,7,7,7,7,7,6},
    {0,6,7,8,8,8,8,8,7,6},
    {0,6,7,8,9,9,9,8,7,6},
    {0,6,7,8,9,10,9,8,7,6},
    {0,6,7,8,9,9,9,8,7,6},
    {0,6,7,8,8,8,8,8,7,6},
    {0,6,7,7,7,7,7,7,7,6},
    {0,6,6,6,6,6,6,6,6,6}
};
int L[MAXC + MAXR * 5], R[MAXC + MAXR * 5], U[MAXC + MAXR * 5], D[MAXC + MAXR * 5], S[MAXC], nRow[MAXC + MAXR * 5], nCol[MAXC + MAXR * 5], head[10][10][10], cnt, map[10][10], best = -1, SCORE = 0;

void init();
int subgrid(int i, int j);
void Ins_node(int c, int cnt);
void Remove(int c);
void Resume(int c);
void dfs(int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    init();
    for (int i = 0; i <= 81 * 4; i++) {
        S[i] = 0;
        L[i] = i - 1;
        R[i] = i + 1;
        U[i] = D[i] = i;
        nCol[i] = 0;
    }
    L[0] = 81 * 4;
    R[81 * 4] = 0;
    cnt = 81 * 4;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++) {
            if (map[i][j]) {
                int k = map[i][j];
                for (int u = 1; u <= 4; u++) {
                    L[cnt + u] = cnt + u - 1;
                    R[cnt + u] = cnt + u + 1;
                    nRow[cnt + u] = 100 * i + 10 * j + k;
                }
                L[cnt + 1] = cnt + 4;
                R[cnt + 4] = cnt + 1;
                head[i][j][k] = cnt + 1;
                Ins_node((i - 1) * 9 + j, cnt + 1);
                Ins_node(81 + (i - 1) * 9 + k, cnt + 2);
                Ins_node(81 * 2 + (j - 1) * 9 + k, cnt + 3);
                Ins_node(81 * 3 + (subgrid(i, j) - 1) * 9 + k, cnt + 4);
                cnt += 4;
            } else
                for (int k = 1; k <= 9; k++) {
                    for (int u = 1; u <= 4; u++) {
                        L[cnt + u] = cnt + u - 1;
                        R[cnt + u] = cnt + u + 1;
                        nRow[cnt + u] = 100 * i + 10 * j + k;
                    }
                    L[cnt + 1] = cnt + 4;
                    R[cnt + 4] = cnt + 1;
                    head[i][j][k] = cnt + 1;
                    Ins_node((i - 1) * 9 + j, cnt + 1);
                    Ins_node(81 + (i - 1) * 9 + k, cnt + 2);
                    Ins_node(81 * 2 + (j - 1) * 9 + k, cnt + 3);
                    Ins_node(81 * 3 + (subgrid(i, j) - 1) * 9 + k, cnt + 4);
                    cnt += 4;
                }
        }
    int k = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            if (map[i][j]) {
                k++;
                SCORE += (map[i][j]) * score[i][j];
                Remove(nCol[head[i][j][map[i][j]]]);
                for (int u = R[head[i][j][map[i][j]]]; u != head[i][j][map[i][j]]; u = R[u])
                    Remove(nCol[u]);
            }
    dfs(k + 1);
    std::cout << best << '\n';
    return 0;
}

void init() {
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            std::cin >> map[i][j];
}

int subgrid(int i, int j) {
    i--;
    j--;
    return (i / 3) * 3 + (j / 3 + 1);
}

void Ins_node(int c, int cnt) {
    U[D[c]] = cnt;
    D[cnt] = D[c];
    U[cnt] = c;
    D[c] = cnt;
    S[c]++;
    nCol[cnt] = c;
}

void Remove(int c) {
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i])
        for (int j = R[i]; j != i; j = R[j]) {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            S[nCol[j]]--;
        }
}

void Resume(int c) {
    for (int i = U[c]; i != c; i=U[i])
        for (int j = L[i]; j != i; j = L[j]) {
            U[D[j]] = D[U[j]] = j;
            S[nCol[j]]++;
        }
    L[R[c]] = R[L[c]] = c;
}

void dfs(int k) {
    if (k>81) {
        best = SCORE > best ? SCORE : best;
        return;
    }
    int c = 0, minnum = 0x7FFFFFFF;
    for (int i = R[0]; i != 0; i=R[i]) {
        if (!S[i])
            return;
        if (S[i] < minnum) {
            minnum = S[i];
            c = i;
        }
    }
    Remove(c);
    for (int i = D[c]; i != c; i = D[i]) {
        int tmp = nRow[i];
        SCORE += (tmp % 10) * (score[tmp / 100][(tmp / 10) % 10]);
        for (int j = R[i]; j != i; j = R[j])
            Remove(nCol[j]);
        dfs(k + 1);
        SCORE -= (tmp % 10) * (score[tmp / 100][(tmp / 10) % 10]);
        for (int j = L[i]; j != i; j = L[j])
            Resume(nCol[j]);
    }
    Resume(c);
}
