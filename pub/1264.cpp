// 1264.cpp
#include <iostream>

int n, map[105][105] = {0x7FFFFFFF}, f[105][105];
template <typename T>
inline T max(const T a, const T b) { return a > b ? a : b;}
int main(int argc, const char * argv[]) {
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            std::cin >> map[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            if (j > 1)
                f[i][j] = map[i][j] + max(f[i - 1][j], f[i - 1][j - 1]);
            else
                f[i][j] = map[i][j] + f[i - 1][j];
        }

    int ans = f[n][1];
    for (int i = 1; i <= n; i++) {
        ans = f[n][i] > ans ? f[n][i] : ans;
    }
    std::cout << ans << std::endl;

    return 0;
}