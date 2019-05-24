// 1309.cpp
#include <iostream>

int n, ans;
int a[10][10], b[10][10];

int check(int x) {
    int sum = x;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            b[i][j] = a[i][j];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 5; j++) {
            if (!b[i][j]) {
                sum++;
                b[i][j] = !b[i][j];
                b[i + 1][j] = !b[i + 1][j];
                b[i + 1][j - 1] = !b[i + 1][j - 1];
                b[i + 1][j + 1] = !b[i + 1][j + 1];
                b[i + 2][j] = !b[i + 2][j];
            }
        }
    }
    for (int i = 1; i <= 5; i++)
        if (!b[5][i])
            return 0x3f3f3f3f;
    return sum;
}

int dfs(int x, int k) {
    if (x > 5) {
        ans = std::min(ans, check(k));
        return 0;
    }
    a[1][x] = !a[1][x];
    a[1][x - 1] = !a[1][x - 1];
    a[1][x + 1] = !a[1][x + 1];
    a[2][x] = !a[2][x];
    dfs(x + 1, k + 1);
    a[1][x] = !a[1][x];
    a[1][x - 1] = !a[1][x - 1];
    a[1][x + 1] = !a[1][x + 1];
    a[2][x] = !a[2][x];
    dfs(x + 1, k);
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d", &n);
    while (n--) {
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 5; j++)
                scanf("%1d", &a[i][j]);
        ans = 0x3f3f3f3f;
        dfs(1, 0);
        if (ans <= 6)
            std::cout << ans << '\n';
        else
            std::cout << "-1\n";
    }
    return 0;
}