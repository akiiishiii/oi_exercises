// 1449_.cpp (Kruskal)
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

struct edge {
    int u;
    int v;
    int c;
    friend std::istream &operator>>(std::istream &is, edge &e);
} e[89701];

struct smallercomp : public std::binary_function<edge, edge, bool> {
    bool operator()(edge const &ea, edge const &eb) { return ea.c < eb.c; }
};

int prt[301];

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }

int main(int argc, char const *argv[]) {
    int n, m, k = 0, ans = 0;
    std::cin >> n >> m;
    for (int i = 0; i <= n; i++)
        prt[i] = i;
    for (int i = 1; i <= m; i++)
        std::cin >> e[i];
    std::sort(e + 1, e + m + 1, smallercomp());
    for (int i = 1; i <= m; i++) {
        int f1 = search(e[i].u), f2 = search(e[i].v);
        if (f1 != f2) {
            ans += e[i].c;
            prt[f1] = f2;
            k++;
            if (k == n - 1) {
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