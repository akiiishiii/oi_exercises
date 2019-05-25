// 1310.cpp
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>

std::pair<long long, long long> calc(int x, long long pos);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        long long a, b;
        std::cin >> n >> a >> b;
        std::pair<long long, long long> ap = calc(n, a - 1);
        std::pair<long long, long long> bp = calc(n, b - 1);
        long long dx = std::abs(ap.first - bp.first),
                  dy = std::abs(ap.second - bp.second);
        std::cout << std::fixed << std::setprecision(0)
                  << sqrt(dx * dx + dy * dy) * 10 << '\n';
    }
    return 0;
}

std::pair<long long, long long> calc(int x, long long pos) {
    if (x == 0)
        return std::make_pair(0, 0);
    long long tot = 1 << (x - 1), s = tot * tot;
    long long z = pos / s, poss = pos % s;
    std::pair<long long, long long> p = calc(x - 1, poss);
    if (z == 0 || z == 3)
        std::swap(p.first, p.second);
    if (z == 3) {
        p.first = tot - p.first - 1;
        p.second = tot - p.second - 1;
    }
    if (z == 1 || z == 2)
        p.first += tot;
    if (z == 3 || z == 2)
        p.second += tot;
    return p;
}