// 2572.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 100010, Maxm = 1000010;
int n, m, tot, ans;
int prt[Maxn];
bool mark[Maxm];

struct edges {
    int x, y, v;
    bool operator<(edges const &w) const { return v < w.v; }
    edges() = default;
    ~edges() = default;
    edges(int u, int v, int w) : x(u), y(v), v(w) {}
} e[Maxm];

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]); }
void kruskal();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y, z; i <= m; i++)
        std::cin >> x >> y >> z, e[i] = edges(x, y, z);
    kruskal();
    std::cout << ans << '\n';
    return 0;
}

void kruskal() {
    std::sort(e + 1, e + 1 + m);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1; i <= m && cnt < n - 1; i++) {
        int x = e[i].x, y = e[i].y, v = e[i].v;
        if (search(x) == search(y))
            continue;
        cnt++, prt[search(x)] = search(y), ans += v, mark[i] = true;
    }
}