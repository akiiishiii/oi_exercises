// 1061.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

struct edge {
    int x, y, val;
    bool operator<(edge const &ee) const { return val < ee.val; }
} e[805];

int cnt, tot = 0, w, h;
int a[45][45], prt[805];

inline int get(int x, int y) { return (x - 1) * w + y; }
int search(int x) { return x == prt[x] ? x : prt[x] = search(prt[x]); }
int kruskal();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> w >> h;
    cnt = w * h;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            std::cin >> a[i][j];
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            if (j < w)
                e[++tot].x = get(i, j), e[tot].y = get(i, j + 1);
            e[tot].val = std::min(a[i][j], a[i][j + 1]);
            if (i < h)
                e[++tot].x = get(i, j), e[tot].y = get(i + 1, j);
            e[tot].val = std::min(a[i][j], a[i + 1][j]);
        }
    std::cout << kruskal() << '\n';
    return 0;
}

int kruskal() {
    int ret = 0;
    for (int i = 1; i <= cnt; i++)
        prt[i] = i;
    std::sort(e + 1, e + tot + 1);
    for (int i = 1, k = 0; i <= tot; i++) {
        int p1 = search(e[i].x), p2 = search(e[i].y);
        if (p1 != p2) {
            prt[p1] = p2;
            ret += e[i].val;
            if (++k == cnt - 1)
                break;
        }
    }
    return ret;
}
