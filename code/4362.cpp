// 4362.cpp
#include <iostream>
#include <algorithm>

int const Maxn = 1010;
double const eps = 1e-5;
int n, m, ans = 0, cnt = 0, pos[Maxn];

struct linear_basis {
    int money;
    double a[Maxn];
    bool operator<(linear_basis const &l) const { return money < l.money; }
} p[Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> p[i].a[j];
    for (int i = 1; i <= n; i++)
        std::cin >> p[i].money;
    std::sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (std::abs(p[i].a[j]) > eps) {
                if (!pos[j]) {
                    pos[j] = i;
                    cnt++;
                    ans += p[i].money;
                    break;
                } else {
                    double e = p[i].a[j] / p[pos[j]].a[j];
                    for (int k = 1; k <= m; k++)
                        p[i].a[k] -= e * p[pos[j]].a[k];
                }
            }
    std::cout << cnt << ' ' << ans << '\n';
    return 0;
}