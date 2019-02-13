#include <cstring>
#include <iostream>

long long a[1005][1005];
bool b[1005][1005];

int main(int argc, const char * argv[]) {
    int n, m;
    std::cin >> n >> m;
    memset(b, true, sizeof(b));
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        b[x][y] = false;
    }
    a[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (b[1][i] == true)
            a[1][i] = a[1][i - 1];
        else
            a[1][i] = 0;
    }
    for (int j = 2; j <= n; j++) {
        if (b[j][1] == true)
            a[j][1] = a[j - 1][1];
        else
            a[j][1] = 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (b[i][j] == true)
                a[i][j] = (a[i - 1][j] + a[i][j - 1]) % 100003;
            else
                a[i][j] = 0;
        }
    }
    std::cout << a[n][n] % 100003;
    return 0;
}