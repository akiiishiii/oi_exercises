// 1653.cpp
#include <cmath>
#include <iostream>
#include <iomanip>

int n;
double f[21], a[21][21];

inline double sqr(double x) { return x * x; }
bool gauss();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> f[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            double t;
            std::cin >> t;
            a[i][j] = 2 * (t - f[j]);
            a[i][n + 1] += sqr(t) - sqr(f[j]);
        }
    gauss();
    for (int i = 1; i <= n; i++)
        std::cout << std::fixed << std::setprecision(3) << a[i][n + 1] << ' ';
    std::cout << '\n';
    return 0;
}

bool gauss() {
    int now = 1, to;
    double t;
    for (int i = 1; i <= n; i++) {
        for (to = now; to <= n; to++)
            if (fabs(a[to][i]) > 1e-6)
                break;
        if (to > n)
            continue;
        if (to != now)
            for (int j = 1; j <= n + 1; j++)
                std::swap(a[to][j], a[now][j]);
        t = a[now][i];
        for (int j = 1; j <= n + 1; j++)
            a[now][j] /= t;
        for (int j = 1; j <= n; j++)
            if (j != now) {
                t = a[j][i];
                for (int k = 1; k <= n + 1; k++)
                    a[j][k] -= t * a[now][k];
            }
        now++;
    }
    for (int i = now; i <= n; i++)
        if (fabs(a[i][n + 1]) > 1e-6)
            return false;
    return true;
}