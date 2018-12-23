// 3918_.cpp
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

int const K = 2;
int ans, dime, cnt = 0;

struct Point {
    int x[2];
    int minn[2], maxx[2];
	bool operator<(Point const &p) const { return x[dime] < p.x[dime]; }
} p[500010], a[1000010], now;

struct Kdtree {
    int l, r;
    Kdtree() { l = r = 0; }
} tree[1000010];

void pushup(int x, int y);
void build(int &x, int l, int r, int dep);
void insert(int &x, int dep);
inline int dist(Point a, Point b);
int guess(int x);
void query(int x, int dep);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n, m, root = 0;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < K; j++) {
                std::cin >> p[i].x[j];
                p[i].maxx[j] = p[i].minn[j] = p[i].x[j];
            }
        build(root, 1, n, 0);
        for (int i = 1, cmd; i <= m; i++) {
            std::cin >> cmd >> now.x[0] >> now.x[1];
            now.maxx[0] = now.minn[0] = now.x[0];
            now.maxx[1] = now.minn[1] = now.x[1];
            if (cmd == 1)
                insert(root, 0);
            else {
                ans = 0x3f3f3f3f;
                query(1, 0);
                std::cout << ans << '\n';
            }
    }
    return 0;
}

void pushup(int x, int y) {
    a[x].minn[0] = std::min(a[x].minn[0], a[y].minn[0]);
    a[x].maxx[0] = std::max(a[x].maxx[0], a[y].maxx[0]);
    a[x].minn[1] = std::min(a[x].minn[1], a[y].minn[1]);
    a[x].maxx[1] = std::max(a[x].maxx[1], a[y].maxx[1]);
}

void build(int &x, int l, int r, int dep) {
    if (!x)
        x = ++cnt;
    dime = dep % K;
    int mid = (l + r) >> 1;
    std::nth_element(p + l, p + mid, p + r + 1);
    a[x] = p[mid];
    if (l <= mid - 1) {
        build(tree[x].l, l, mid - 1, dep + 1);
        pushup(x, tree[x].l);
    }
    if (r >= mid + 1) {
        build(tree[x].r, mid + 1, r, dep + 1);
        pushup(x, tree[x].r);
    }
}

void insert(int &x, int dep) {
    if (!x) {
        x = ++cnt;
        a[x] = now;
        tree[x] = Kdtree();
        return;
    }
    dime = dep % K;
    if (now < a[x]) {
        insert(tree[x].l, dep + 1);
        pushup(x, tree[x].l);
    } else {
        insert(tree[x].r, dep + 1);
        pushup(x, tree[x].r);
    }
}

inline int dist(Point a, Point b) {
    return abs(a.x[0] - b.x[0]) + abs(a.x[1] - b.x[1]);
}

int guess(int x) {
    int x0, x1;
    if (now.x[0] >= a[x].minn[0] && now.x[0] <= a[x].maxx[0])
        x0 = 0;
    else
        x0 = std::min(abs(now.x[0] - a[x].maxx[0]), abs(now.x[0] - a[x].minn[0]));
    if (now.x[1] >= a[x].minn[1] && now.x[1] <= a[x].maxx[1])
        x1 = 0;
    else
        x1 = std::min(abs(now.x[1] - a[x].maxx[1]), abs(now.x[1] - a[x].minn[1]));
    return x0 + x1;
}

void query(int x, int dep) {
    dime = dep % K;
    int dl, dr;
    if (tree[x].l)
        dl = guess(tree[x].l);
    else
        dl = 0x3f3f3f3f;
    if (tree[x].r)
        dr = guess(tree[x].r);
    else
        dr = 0x3f3f3f3f;
    int tmp = dist(a[x], now);
    if (tmp < ans)
        ans = tmp;
    if (dl < dr) {
        if (dl < ans)
            query(tree[x].l, dep + 1);
        if (dr < ans)
            query(tree[x].r, dep + 1);
    } else {
        if (dr < ans)
            query(tree[x].r, dep + 1);
        if (dl < ans)
            query(tree[x].l, dep + 1);
    }
}