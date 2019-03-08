// 4544.cpp
#include <cstring>
#include <iostream>

int u[35], v[35], n;
int a[35][35];

int gauss();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        memset(a, 0, sizeof a);
        for (int i = 0; i < n; i++)
            std::cin >> u[i];
        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
            a[i][n] = v[i] ^ u[i];
            a[i][i] = 1;
        }
        int x, y;
        while (std::cin >> x >> y) {
            if (x == 0 && y == 0)
                break;
            a[y - 1][x - 1] = 1;
        }
        int ans = gauss();
        if (ans == -1)
            std::cout << "Oh,it's impossible~!!\n";
        else
            std::cout << ans << '\n';
    }
    return 0;
}


int gauss() {
    int i, j;
    for (i = 0, j = 0; i < n && j < n; j++) {
        int k;
        for (k = i; k < n; k++)
            if (a[k][j])
                break;
        if (a[k][j]) {
            for (int r = 0; r <= n; r++)
                std::swap(a[i][r], a[k][r]);
            for (int r = 0; r < n; r++)
                if (a[r][j] && r != i)
                    for (k = 0; k <= n; k++)
                        a[r][k] ^= a[i][k];
            i++;
        }
    }
    for (j = i; j < n; j++)
        if (a[j][n])
            return -1;
    return 1 << (n - i);
}
