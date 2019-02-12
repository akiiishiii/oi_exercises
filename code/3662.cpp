// 3662.cpp
#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

double const eps = 1e-9;
int n, x[1005], y[1005], z[1005], prt[1005];
double c[1005][1005], h[1005][1005], a[1005][1005], d[1005];
bool vst[1005];
std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> q;

double prim();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> n && n) {
        double ans = 0, tmp;
        for (int i = 1; i <= n; i++)
            std::cin >> x[i] >> y[i] >> z[i];
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                c[i][j] = c[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) +
                                         (y[i] - y[j]) * (y[i] - y[j]));
                h[i][j] = h[j][i] = fabs(double(z[i] - z[j]));
            }
        while (true) {
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                    a[i][j] = a[j][i] = h[i][j] - c[i][j] * ans;
            tmp = prim();
            if (fabs(tmp - ans) < eps)
                break;
            ans = tmp;
        }
        std::cout << std::fixed << std::setprecision(3) << ans << '\n';
    }
    return 0;
}

double prim() {
    memset(vst, false, sizeof(vst));
    d[1] = 0;
    double ans1 = 0.0, ans2 = 0.0;
    vst[1] = true;
    for (int i = 2; i <= n; i++) {
        d[i] = a[1][i];
        q.push(std::make_pair(d[i], i));
        prt[i] = 1;
    }
    while (!q.empty()) {
        std::pair<double, int> u = q.top();
        q.pop();
        int x = u.second;
        if (vst[x])
            continue;
        vst[x] = true;
        ans1 += h[prt[x]][x];
        ans2 += c[prt[x]][x];
        for (int i = 1; i <= n; i++)
            if (!vst[i] && d[i] > a[x][i]) {
                d[i] = a[x][i];
                prt[i] = x;
                q.push(std::make_pair(d[i], i));
            }
    }
    return ans1 / ans2;
}