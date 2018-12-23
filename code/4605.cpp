// 4605.cpp
#include <iostream>
#include <queue>
#include <algorithm>

int n, k, root, p[2], dime;
struct point {
    int d[2];
    int maxx[2], minn[2];
    int l, r;
    bool operator<(point const &p) const { return d[dime] < p.d[dime]; }
} a[100005];
std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q;

inline long long sqr(const int &x) { return (long long)x * x; }
void pushup(int x);
void build(int &x, int l, int r, int now);
long long ask(int x);
void query(int x);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].d[0] >> a[i].d[1];
    build(root, 1, n, 0);
    for (int i = 1; i <= 2 * k; i++)
        q.push(0);
    for (int i = 1; i <= n; i++) {
        p[0] = a[i].d[0];
        p[1] = a[i].d[1];
        query(root);
    }
    std::cout << q.top() << "\n";
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

void build(int &x, int l, int r, int now) {
    int mid = (l + r) >> 1;
    dime = now, x = mid;
    std::nth_element(a + l, a + mid, a + r + 1);
    for (int i = 0; i < 2; i++)
        a[x].maxx[i] = a[x].minn[i] = a[x].d[i];
    if (l < mid)
        build(a[x].l, l, mid - 1, now ^ 1);
    if (r > mid)
        build(a[x].r, mid + 1, r, now ^ 1);
    pushup(x);
}

long long ask(int x) {
    if (!x)
        return 0;
    return std::max(sqr(a[x].minn[0] - p[0]), sqr(a[x].maxx[0] - p[0])) + std::max(sqr(a[x].minn[1] - p[1]), sqr(a[x].maxx[1] - p[1]));
}

void query(int x) {
    long long dist = sqr(a[x].d[0] - p[0]) + sqr(a[x].d[1] - p[1]);
    if (dist > q.top()) {
        q.pop();
        q.push(dist);
    }
    long long dl = ask(a[x].l), dr = ask(a[x].r);
    if (dl > dr) {
        if (dl > q.top())
            query(a[x].l);
        if (dr > q.top())
            query(a[x].r);
    } else {
        if (dr > q.top())
            query(a[x].r);
        if (dl > q.top())
            query(a[x].l);
    }
}