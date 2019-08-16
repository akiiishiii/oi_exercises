// 1945.cpp
#include <cstring>
#include <iostream>

int n, q;
int ch[101][3], f[101][101], map[101][101], a[101];

void make_tree(int v);
int dp(int i, int j);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    memset(f, 0, sizeof f);
    std::cin >> n >> q;
    q++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            map[i][j] = -1;
    for (int i = 1, x, y, z; i < n; i++) {
        std::cin >> x >> y >> z;
        map[x][y] = map[y][x] = z;
    }
    make_tree(1);
    std::cout << dp(1, q) << '\n';
    return 0;
}

void make_tree(int v) {
    for (int i = 1; i <= n; i++)
        if (map[v][i] >= 0) {
            ch[v][1] = i;
            a[i] = map[v][i];
            map[v][i] = map[i][v] = -1;
            make_tree(i);
            break;
        }
    for (int i = 1; i <= n; i++)
        if (map[v][i] >= 0) {
            ch[v][2] = i;
            a[i] = map[v][i];
            map[v][i] = map[i][v] = -1;
            make_tree(i);
            break;
        }
}

int dp(int i, int j) {
    if (j == 0)
        return 0;
    if ((ch[i][1] == 0) && (ch[i][2] == 0))
        return a[i];
    if (f[i][j] > 0)
        return f[i][j];
    for (int k = 0; k <= j - 1; k++)
        f[i][j] =
            std::max(f[i][j], dp(ch[i][1], k) + dp(ch[i][2], j - k - 1) + a[i]);
    return f[i][j];
}