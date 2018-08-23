// 1456.cpp
#include <queue>
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
} e[44851];

struct smallercomp : public std::binary_function<edge, edge, bool> {
    bool operator()(edge const &ea, edge const &eb) { return ea.c < eb.c; }
};

int prt[301];

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, k = 0;
    bool flag = false;
    std::priority_queue<int, std::vector<int>, std::greater<int> > ans;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        prt[i] = i;
    for (int i = 0; i < m; i++)
        std::cin >> e[i];
    std::sort(e, e + m, smallercomp());
    for (int t = 0; t < m - 1; t++) {
        for (int i = t; i < m; i++) {
            int f1 = search(e[i].u), f2 = search(e[i].v);
            if (f1 != f2) {
                prt[f1] = f2;
                k++;
                if (k == n - 1) {
                    ans.push(e[i].c - e[t].c);
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            std::cout << "-1\n";
            return 0;
        }
    }
    std::cout << ans.top() << '\n';
    return 0;
}

std::istream &operator>>(std::istream &is, edge &e) {
    is >> e.u >> e.v >> e.c;
    return is;
}