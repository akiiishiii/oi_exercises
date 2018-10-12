// 1634.cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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
    int n, sum = 0, di = 0;
    std::cin >> n;
    vy.resize(n);
    for (int i = 0, tmpp, tmpq; i < n; i++) {
        std::cin >> vy[i].x >> vy[i].y >> tmpp >> tmpq;
        vy[i].w = tmpq * tmpp;
        sum += vy[i].w;
    }
    std::sort(vy.begin(), vy.end(), cmpx);
    for (int t = 0; di < vy.size(); di++) {
        t += vy[di].w;
        if (t >= (sum + 1) / 2)
            break;
    }
    std::cout << vy[di].x << ' ';
    di = 0;
    std::sort(vy.begin(), vy.end(), cmpy);
    for (int t = 0; di < vy.size(); di++) {
        t += vy[di].w;
        if (t >= (sum + 1) / 2)
            break;
    }
    std::cout << vy[di].y << '\n';
    return 0;
}