// 1634.cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

struct pureiya {
    int x;
    int y;
    int w;
    pureiya() = default;
    ~pureiya() = default;
};

bool cmpx(pureiya const &a, pureiya const &b) { return (a.x == b.x ? a.y < b.y : a.x < b.x); }
bool cmpy(pureiya const &a, pureiya const &b) { return (a.y == b.y ? a.x < b.x : a.y < b.y); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<pureiya> vy;
    int n, sum = 0, di = 0, dj = 0;
    double ans = 0;
    std::cin >> n;
    vy.resize(n);
    for (int i = 0; i < n; i++)
        std::cin >> vy[i].w, sum += vy[i].w;
    for (int i = 0; i < n; i++)
        std::cin >> vy[i].x >> vy[i].y;
    std::sort(vy.begin(), vy.end(), cmpx);
    for (int t = 0; di < vy.size(); di++) {
        t += vy[di].w;
        if (t >= (sum + 1) / 2)
            break;
    }
    di = vy[di].x;
    std::sort(vy.begin(), vy.end(), cmpy);
    for (int t = 0; dj < vy.size(); dj++) {
        t += vy[dj].w;
        if (t >= (sum + 1) / 2)
            break;
    }
    dj = vy[dj].y;
    for (int i = 0; i < n; i++)
        ans += vy[i].w * (abs(vy[i].x - di) + abs(vy[i].y - dj));
    std::cout << std::fixed << std::setprecision(2) << ans << '\n';
    return 0;
}