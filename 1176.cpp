// 1176.cpp
#include <iostream>
#include <algorithm>
#include <vector>

struct pos {
    int a, b;
    bool operator<(const pos & p) const { return a == p.a ? b < p.b : a < p.a;}
};

int main(int argc, const char * argv[]) {
    int x1, x2, y1, y2, n;
    std::vector<pos> p;
    std::cin >> x1 >> y1 >> x2 >> y2 >> n;
    p.resize(n + 1);
    for (int i = 1, x, y; i <= n; i++) {
        std::cin >> x >> y;
        p[i].a = (x - x1) * (x - x1) + (y - y1) * (y - y1);
        p[i].b = (x - x2) * (x - x2) + (y - y2) * (y - y2);
    }
    std::sort(p.begin(), p.end());
    int ans = p[n].a, r2 = 0;
    for (std::vector<pos>::iterator it = p.end() - 1; it != p.begin(); it--) {
        ans = (*it).a + r2 < ans ? (*it).a + r2 : ans;
        r2 = r2 < (*it).b ? (*it).b : r2;
    }
    ans = ans > r2 ? ans : r2;
    std::cout << ans << std::endl;
    return 0;
}