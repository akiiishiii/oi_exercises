// 3506.cpp
#include <algorithm>
#include <iostream>

struct cow {
    long long x, y;
    bool operator<(cow const &c) { return x - c.y < c.x - y; }
} w[50005];

int n;
long long ans = 0xcfcfcfcfcfcfcfcf, num;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> w[i].x >> w[i].y;
    std::sort(w + 1, w + n + 1);
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, num - w[i].y), num += w[i].x;
    std::cout << ans << '\n';
    return 0;
}