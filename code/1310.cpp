// 1310.cpp
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>

std::pair<long long, long long> recur(int stage, long long id) {
    if (stage == 0)
        return std::make_pair(0, 0);
    long long max = 1 << (stage - 1), s = max * max;
    long long z = id / s, idsp = id % s;
    std::pair<long long, long long> psp = recur(stage - 1, idsp);
    if (z == 0 || z == 3)
        std::swap(psp.first, psp.second);
    if (z == 3) {
        psp.first = max - psp.first - 1;
        psp.second = max - psp.second - 1;
    }
    if (z == 1 || z == 2)
        psp.first += max;
    if (z == 3 || z == 2)
        psp.second += max;
    return psp;
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        long long a, b;
        std::cin >> n >> a >> b;
        std::pair<long long, long long> ap = recur(n, a - 1);
        std::pair<long long, long long> bp = recur(n, b - 1);
        long long dx = std::abs(ap.first - bp.first),
                  dy = std::abs(ap.second - bp.second);
        std::cout << std::fixed << std::setprecision(0)
                  << sqrt(dx * dx + dy * dy) * 10 << '\n';
    }
    return 0;
}
