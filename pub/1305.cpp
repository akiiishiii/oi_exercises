// 1305.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct metal {
    metal() = default;
    metal(int _n, int _v) : n(_n), v(_v) { price = double(v) / n; }
    ~metal() = default;
    bool operator<(const metal & m) const { return price < m.price; }
    int n, v;
    double price;
};

int main(int argc, const char * argv[]) {
    int w, s, n, v, totn = 0;
    double totv = 0;
    std::vector<metal> m;
    std::cin >> w >> s;
    for (int i = 0; i < s; i++) {
        std::cin >> n >> v;
        m.push_back(metal(n, v));
    }
    std::sort(m.begin(), m.end());

    return 0;
}