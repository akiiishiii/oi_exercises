// 1775.cpp
#include <iostream>
#include <iomanip>

double f[100005];
int hikouki[100005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    while (std::cin >> n >> m && (n || m)) {
        for (int i = 0; i <= n; i++)
            f[i] = 0, hikouki[i] = -1;
        for (int i = 0, a, b; i < m; i++)
            std::cin >> a >> b, hikouki[a] = b;
        for (int i = n - 1; i >= 0; i--) {
            if (hikouki[i] != -1)
                f[i] = f[hikouki[i]];
            else {
                for (int j = 1; j <= 6; j++)
                    f[i] += 1.0 / 6 * f[(i + j >= n) ? n : (i + j)];
                f[i]++;
            }
        }
        std::cout << std::fixed << std::setprecision(4) << f[0] << '\n';
    }
    return 0;
}