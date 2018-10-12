// 1004.cpp
#include <iostream>
#include <algorithm>
#include <cstring>

int a[3001] = {0}, b[3001] = {0}, n, f[3001][3001];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(f, 0, sizeof f);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];
    for (int i = 1; i <= n; i++) {
        int val = 0;
        if (b[0] < a[i])
            val = f[i - 1][0];
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j])
                f[i][j] = val + 1;
            else
                f[i][j] = f[i - 1][j];
            if (b[j] < a[i])
                val = std::max(val, f[i - 1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, f[n][i]);
    std::cout << ans << '\n';
    return 0;
}
