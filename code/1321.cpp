// 1217.cpp
#include <algorithm>
#include <cmath>
#include <iostream>

std::pair<double, double> area[1010];
int n, d, cnt;

void calc(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, t, ans;
    while (std::cin >> n >> d, n || d) {
        cnt = t = 0;
        ans = 1;
        for (int i = 0, x, y; i < n; i++)
            std::cin >> x >> y, calc(x, y);
        std::sort(area, area + cnt);
        for (int i = 0; i < cnt; i++)
            if (area[i].second > area[t].first)
                t = i, ans++;
        std::cout << ans << '\n';
    }
    return 0;
}

void calc(int x, int y) {
    if (y > d)
        return;
    double m = sqrt(d * d - y * y);
    area[cnt++] = std::make_pair(x + m, x - m);
    return;
}