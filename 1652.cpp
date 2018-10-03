// 1652.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

double a[105][105], ans[105];
int n;

void simplify(int l);
int check();
int Gauss();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            std::cin >> a[i][j];
    int res = Gauss();
    if (res != 1) {
        std::cout << res << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << 'x' << i << '=';
        if (fabs(ans[i]) <= 1e-7)
            std::cout << "0\n";
        else
            std::cout << std::fixed << std::setprecision(2) << ans[i] << '\n';
    }
    return 0;
}

void simplify(int l) {
    int r = l;
    double Max = fabs(a[r][l]);
    for (int i = l + 1; i <= n; i++)
        if (fabs(a[i][l]) > Max) {
            Max = fabs(a[i][l]);
            r = i;
        }
    if (r != l)
        for (int i = l; i <= n + 1; i++)
            std::swap(a[l][i], a[r][i]);
    for (int i = l + 1; i <= n; i++) {
        if (fabs(a[l][l]) <= 1e-7)
            continue;
        double mul = a[i][l] / a[l][l];
        for (int j = l; j <= n + 1; j++)
            a[i][j] -= a[l][j] * mul;
    }
}

int check() {
    for (int i = 1; i <= n; i++) {
        bool b = false;
        for (int j = 1; j <= n; j++)
            if (fabs(a[i][j]) > 1e-7) {
                b = true;
                break;
            }
        if (!b) {
            if (fabs(a[i][n + 1]) <= 1e-7)
                return 0;
            else
                return -1;
        }
    }
    return 1;
}

int Gauss() {
    for (int i = 1; i <= n; i++)
        simplify(i);
    int res = check();
    if (res != 1)
        return res;
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++)
            a[i][n + 1] -= a[i][j] * ans[j];
        if (fabs(a[i][i]) <= 1e-7) {
            if (fabs(a[i][n + 1]) <= 1e-7)
                return 0;
            else
                return -1;
        }
        ans[i] = a[i][n + 1] / a[i][i];
    }
    return 1;
}
