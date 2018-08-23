// 1454.cpp
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

struct pos {
    int x;
    int y;
    friend std::istream &operator>>(std::istream &is, pos &p);
    friend inline long double dist(pos const &a, pos const &b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
};

struct edge {
    int u;
    int v;
    long double c;
    edge() = default;
    ~edge() = default;
    edge(int mu, int mv, long double mc) : u(mu), v(mv), c(mc) {}
};

struct smallercomp : public std::binary_function<edge, edge, bool> {
    bool operator()(edge const &ea, edge const &eb) { return ea.c < eb.c; }
};

std::vector<int> prt;
bool built[1001][1001];

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }

int main(int argc, char const *argv[]) {
    std::vector<pos> p;
    std::vector<edge> e;
    int n, m, k = 0;
    long double ans = 0.0;
    std::cin >> n >> m;
    prt.resize(n + 1);
    p.resize(n);
    memset(built, false, sizeof built);
    for (int i = 0; i <= n; i++)
        prt[i] = i;
    for (auto &&it : p)
        std::cin >> it;
    for (int i = 0, u, v; i < m; i++) {
        std::cin >> u >> v;
        built[u][v] = built[v][u] = true;
        e.push_back(edge(u, v, 0));
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (built[i][j] || built[j][i] || i == j)
                continue;
            else
                e.push_back(edge(i, j, dist(p[i - 1], p[j - 1])));
        }
            std::sort(e.begin(), e.end(), smallercomp());
    for (int i = 0; i < e.size(); i++) {
        int f1 = search(e[i].u), f2 = search(e[i].v);
        if (f1 != f2) {
            ans += e[i].c;
            prt[f1] = f2;
            k++;
            if (k == n - 1) {
                std::cout << std::fixed << std::setprecision(2) << ans << '\n';
                return 0;
            }
        }
    }
    return 0;
}

std::istream &operator>>(std::istream &is, pos &p) {
    is >> p.x >> p.y;
    return is;
}