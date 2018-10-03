// 1652.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

double a[105][105], ans[105];
int n;

void Simplify(int Line);
int Check();
int Gauss();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            std::cin >> a[i][j];
    int tmp = Gauss();
    if (tmp != 1) {
        std::cout << tmp << '\n';
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

void Simplify(int Line) {
    int Row = Line;
    double Max = fabs(a[Row][Line]);
    for (int i = Line + 1; i <= n; i++)
        if (fabs(a[i][Line]) > Max) {
            Max = fabs(a[i][Line]);
            Row = i;
        }
    if (Row != Line)
        for (int i = Line; i <= n + 1; i++)
            std::swap(a[Line][i], a[Row][i]);
    for (int i = Line + 1; i <= n; i++) {
        if (fabs(a[Line][Line]) <= 1e-7)
            continue;
        double Multiple = a[i][Line] / a[Line][Line];
        for (int j = Line; j <= n + 1; j++)
            a[i][j] -= a[Line][j] * Multiple;
    }
}

int Check() {
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
        Simplify(i);
    int tmp = Check();
    if (tmp != 1)
        return tmp;
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
