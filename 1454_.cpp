#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>

struct point {
    int x;
    int y;
} d[1002];

struct edge {
    int u;
    int v;
    double c;
    bool operator<(edge const &e) const { return c < e.c; }
} e[1000002];

int n, m, prt[1002], mm;
double ans = 0;

int search(int x) { return (prt[x] == x ? prt[x] : prt[x] = search(prt[x])); }
double dist(int i, int j) { return sqrt((long long)(d[i].x - d[j].x) * (d[i].x - d[j].x) + (long long)(d[i].y - d[j].y) * (d[i].y - d[j].y)); }
void add_edge(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> d[i].x >> d[i].y;
        prt[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, r1, r2;
        std::cin >> x >> y;
        r1 = search(x);
        r2 = search(y);
        prt[r2] = r1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            int r1 = search(i), r2 = search(j);
            if (r1 != r2)
                add_edge(i, j);
        }
    std::sort(e + 1, e + mm + 1);
    for (int i = 1; i <= mm; i++) {
        int r1, r2;
        r1 = search(e[i].u);
        r2 = search(e[i].v);
        if (r1 != r2) {
            ans += e[i].c;
            prt[r2] = r1;
        }
    }
    std::cout << std::fixed << std::setprecision(2) << ans << '\n';
    return 0;
}

void add_edge(int x, int y) {
    double z = dist(x, y);
    mm++;
    e[mm].u = x;
    e[mm].v = y;
    e[mm].c = z;
}