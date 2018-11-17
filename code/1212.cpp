// 1212.cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

int const Maxn = 1001;

struct segment_tree {
    double l, r;
    double sum, d;
} tree[Maxn << 3];

struct rectangle {
    double x, y1, y2;
    int d;
    bool operator<(rectangle const &n) const { return x < n.x; }
} p[Maxn << 3];

double s[Maxn << 3];

void build(int v, int l, int r);
void update(int v, double y1, double y2, int d);
void push_up(int v);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int temp = 1, n;
    double x1, y1, x2, y2, ans;
    while ((std::cin >> n) && n) {
        ans = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> x1 >> y1 >> x2 >> y2;
            p[i].x = x1;
            p[i].y1 = p[i + n].y1 = s[i + 1] = y1;
            p[i].y2 = p[i + n].y2 = s[i + n + 1] = y2;
            p[i].d = 1;
            p[i + n].x = x2;
            p[i + n].d = -1;
        }
        std::sort(s + 1, s + ((n << 1) | 1));
        std::sort(p, p + (n << 1));
        build(1, 1, n << 1);
        update(1, p[0].y1, p[0].y2, p[0].d);
        for (int i = 1; i < n << 1; i++) {
            ans += (p[i].x - p[i - 1].x) * tree[1].sum;
            update(1, p[i].y1, p[i].y2, p[i].d);
        }
        std::cout << "Test case #" << temp++
                  << "\nTotal explored area: " << std::fixed
                  << std::setprecision(2) << ans << "\n\n";
    }
    return 0;
}

void build(int v, int l, int r) {
        tree[v].l = s[l];
        tree[v].r = s[r];
        tree[v].d = tree[v].sum = 0;
    if (r - l > 1) {
        build(v << 1, l, (l + r) >> 1);
        build((v << 1) | 1, (l + r) >> 1, r);
        push_up(v);
    }
}

void update(int v, double y1, double y2, int d) {
    if (tree[v].l == y1 && tree[v].r == y2) {
        tree[v].d += d;
    } else {
        if (tree[v << 1].r > y1)
            update(v << 1, y1, std::min(tree[v << 1].r, y2), d);
        if (tree[(v << 1) | 1].l < y2)
            update((v << 1) | 1, std::max(tree[(v << 1) | 1].l, y1), y2, d);
    }
    push_up(v);
}

void push_up(int v) {
    if (tree[v].d > 0)
        tree[v].sum = tree[v].r - tree[v].l;
    else
        tree[v].sum = tree[v << 1].sum + tree[(v << 1) | 1].sum;
}