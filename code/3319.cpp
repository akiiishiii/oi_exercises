// 3319.cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>

long long ansmax, ansmin;
int dime;
int p[50010];
struct point {
    int d[3];
    int maxx[3], minn[3];
    int l, r;
    bool operator<(point const &x) const { return d[dime] < x.d[dime]; }
} a[100010];

void pushup(int x);
void build(int &rt, int l, int r, int d);
void askmax(int &maxx, int x, int y);
void askmin(int &minn, int x, int y);
void query_max(int x, int d, int y);
void query_min(int x, int d, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, rt;
    long long ans = 0x3f3f3f3f;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].d[0] >> a[i].d[1];
    build(rt, 1, n, 0);
    for (int i = 1; i <= n; i++) {
        ansmax = -1, ansmin = 0x3f3f3f3f;
        query_max(rt, 0, i);
        query_min(rt, 0, i);
        ans = std::min(ans, ansmax - ansmin);
    }
    std::cout << ans << "\n";
    return 0;
}

void pushup(int x) {
    for (int i = 0; i < 2; i++) {
        if (a[x].l) {
            a[x].maxx[i] = std::max(a[x].maxx[i], a[a[x].l].maxx[i]);
            a[x].minn[i] = std::min(a[x].minn[i], a[a[x].l].minn[i]);
        }
        if (a[x].r) {
            a[x].maxx[i] = std::max(a[x].maxx[i], a[a[x].r].maxx[i]);
            a[x].minn[i] = std::min(a[x].minn[i], a[a[x].r].minn[i]);
        }
    }
}

void build(int &rt, int l, int r, int d) {
    int mid = (l + r) >> 1;
    dime = d, rt = mid;
    std::nth_element(a + l, a + mid, a + r + 1);
    for (int i = 0; i < 2; i++)
        a[rt].maxx[i] = a[rt].minn[i] = a[rt].d[i];
    if (l < mid)
        build(a[rt].l, l, mid - 1, d ^ 1);
    if (r > mid)
        build(a[rt].r, mid + 1, r, d ^ 1);
    pushup(rt);
}

void askmax(int &maxx, int x, int y) {
    maxx = 0;
    for (int i = 0; i < 2; i++)
        maxx += std::max(abs(a[x].minn[i] - a[y].d[i]),
                         abs(a[x].maxx[i] - a[y].d[i]));
}

void askmin(int &minn, int x, int y) {
    minn = 0;
    for (int i = 0; i < 2; i++) {
        if (a[y].d[i] < a[x].minn[i])
            minn += a[x].minn[i] - a[y].d[i];
        if (a[y].d[i] > a[x].maxx[i])
            minn += a[y].d[i] - a[x].maxx[i];
    }
}

void query_max(int x, int d, int y) {
    long long dist =
        (long long)(abs(a[x].d[0] - a[y].d[0]) + abs(a[x].d[1] - a[y].d[1]));
    int dl = -1, dr = -1;
    if (y != x)
        ansmax = std::max(ansmax, dist);
    if (a[x].l)
        askmax(dl, a[x].l, y);
    if (a[x].r)
        askmax(dr, a[x].r, y);
    if (dl > dr) {
        if (dl > ansmax)
            query_max(a[x].l, d ^ 1, y);
        if (dr > ansmax)
            query_max(a[x].r, d ^ 1, y);
    } else {
        if (dr > ansmax)
            query_max(a[x].r, d ^ 1, y);
        if (dl > ansmax)
            query_max(a[x].l, d ^ 1, y);
    }
}

void query_min(int x, int d, int y) {
    long long dist = abs(a[x].d[0] - a[y].d[0]) + abs(a[x].d[1] - a[y].d[1]);
    int dl = 0x3f3f3f3f, dr = 0x3f3f3f3f;
    if (y != x)
        ansmin = std::min(ansmin, dist);
    if (a[x].l)
        askmin(dl, a[x].l, y);
    if (a[x].r)
        askmin(dr, a[x].r, y);
    if (dl < dr) {
        if (dl < ansmin)
            query_min(a[x].l, d ^ 1, y);
        if (dr < ansmin)
            query_min(a[x].r, d ^ 1, y);
    } else {
        if (dr < ansmin)
            query_min(a[x].r, d ^ 1, y);
        if (dl < ansmin)
            query_min(a[x].l, d ^ 1, y);
    }
}