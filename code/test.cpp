#include <cstring>
#include <iostream>

int a[105] = {0}, s[105] = {0}, fminn[105][205], fmaxx[105][205];
int n;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int minn = 0, maxx = 0x3f3f3f3f;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], a[i + n] = a[i];
    for (int i = 1; i <= n * 2; i++) {
        s[i] = s[i - 1] + a[i];
        fminn[i][i] = fmaxx[i][i] = 0;
    }
    for (int t = 1; t <= n - 1; t++)
        for (int i = 1; i <= 2 * n - t; i++) {
            int j = i + t;
            fmaxx[i][j] = 0x3f3f3f3f;
            fminn[i][j] = 0;
            for (int k = i; k < j; k++) {
                fminn[i][j] =
                    std::max(fminn[i][j], fminn[i][k] + fminn[k + 1][j]);
                fmaxx[i][j] =
                    std::min(fmaxx[i][j], fmaxx[i][k] + fmaxx[k + 1][j]);
            }
            fminn[i][j] = fminn[i][j] + s[j] - s[i - 1];
            fmaxx[i][j] = fmaxx[i][j] + s[j] - s[i - 1];
        }
    for (int i = 1; i <= n; i++) {
        minn = std::max(minn, fminn[i][i + n - 1]);
        maxx = std::min(maxx, fmaxx[i][i + n - 1]);
    }
    std::cout << maxx << '\n' << minn << '\n';
    return 0;
}