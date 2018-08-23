// 1453.cpp
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

struct edge {
    int u;
    int v;
    int c;
    edge() = default;
    ~edge() = default;
    edge(int mu, int mv, int mc) : u(mu), v(mv), c(mc) {}
    friend std::istream &operator>>(std::istream &is, edge &e);
};

struct smallercomp : public std::binary_function<edge, edge, bool> {
    bool operator()(edge const &ea, edge const &eb) { return ea.c < eb.c; }
};

int prt[501];
std::vector<edge> e;

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }

int main(int argc, char const *argv[]) {
    int n, k = 0, ans = 0;
    std::cin >> n;
    for (int i = 0; i <= n; i++) {
        prt[i] = i;
    }
    for (int i = 1, c; i <= n; i++) {
        std::cin >> c;
        e.push_back(edge(0, i, c));
    }
    for (int i = 1, c; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            std::cin >> c;
            e.push_back(edge(i, j, c));
        }
    std::sort(e.begin(), e.end(), smallercomp());
    for (int i = 0; i < e.size(); i++) {
        int f1 = search(e[i].u), f2 = search(e[i].v);
        if (f1 != f2) {
            ans += e[i].c;
            prt[f1] = f2;
            k++;
            if (k == n) {
                std::cout << ans << '\n';
                return 0;
            }
        }
    }
    std::cout << "Impossible\n";
    return 0;
}

std::istream &operator>>(std::istream &is, edge &e) {
    is >> e.u >> e.v >> e.c;
    return is;
}