// 1457.cpp
#include <cmath>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>

int prt[501];
std::pair<int, int> pos[501];

struct edge {
    int u;
    int v;
    double c;
    edge() = default;
    ~edge() = default;
    edge(int mu, int mv) : u(mu), v(mv) { c = sqrt((long long)(pos[mu].first - pos[mv].first) * (pos[mu].first - pos[mv].first) + (long long)(pos[mu].second - pos[mv].second) * (pos[mu].second - pos[mv].second)); }
};
std::vector<edge> e;

struct smallercomp : public std::binary_function<edge, edge, bool> {
    bool operator()(edge const &ea, edge const &eb) { return ea.c < eb.c; }
};

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k, m = 0, ans = 0;
    std::cin >> k >> n;
    if (k >= n) {
        std::cout << "0.00\n";
        return 0;
    }
    for (int i = 0; i <= n; i++)
        prt[i] = i;
    for (int i = 1; i <= n; i++)
        std::cin >> pos[i].first >> pos[i].second;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            e.push_back(edge(i, j));
    std::sort(e.begin(), e.end(), smallercomp());
    for (int i = 0; i < e.size(); i++) {
        int f1 = search(e[i].u), f2 = search(e[i].v);
        if (f1 != f2) {
            ans += e[i].c;
            prt[f1] = f2;
            m++;
            if (m == n - k) {
                std::cout << std::fixed << std::setprecision(2) << e[i].c << '\n';
                return 0;
            }
        }
    }
    std::cout << "0.00\n";
    return 0;
}