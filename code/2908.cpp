// 2908.cpp
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

struct Edge {
    int u, v, w;
    Edge() = default;
    Edge(int a, int b, int c) : u(a), v(b), w(c) {}
    bool operator<(Edge const &b) const { return w < b.w; }
};

int const Maxn = 50;
int n, ans = 0, prt[Maxn];
std::vector<Edge> e;
std::pair<int, int> p[Maxn];

int search(int u) { return prt[u] == u ? u : prt[u] = search(prt[u]); }
inline int dist(std::pair<int, int> const &a, std::pair<int, int> const &b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].first >> p[i].second;
        prt[i] = i;
        for (int j = 0; j < i; j++)
            e.push_back(Edge(i, j, (dist(p[i], p[j]) - 1) / 2 + 1));
    }
    std::sort(e.begin(), e.end());
    for (int i = 0; i < e.size(); i++)
        if (search(e[i].u) != search(e[i].v)) {
            prt[search(e[i].u)] = search(e[i].v);
            ans = std::max(ans, e[i].w);
        }
    std::cout << ans << '\n';
    return 0;
}

inline int dist(std::pair<int, int> const &a, std::pair<int, int> const &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}