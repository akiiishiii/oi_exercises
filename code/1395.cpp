// 1395.cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

int q[6], dime, k;
std::priority_queue<std::pair<long long, int>> pq;
struct point {
    int d[6];
    int maxx[6], minn[6];
    int l, r;
    bool operator<(point const &x) const { return d[dime] < x.d[dime]; }
} a[50005];

void pushup(int x);
void build(int &root, int l, int r, int d);
void output();
inline long long dist(int x);
long long guess(int x);
void query(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n, t, rt;
    while (std::cin >> n >> k) {
        memset(a, 0, sizeof(a));
        while (!pq.empty())
            pq.pop();
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < k; j++)
                std::cin >> a[i].d[j];
        build(rt, 1, n, 0);
        std::cin >> t;
        for (int i = 1; i <= t; i++) {
            for (int j = 0; j < k; j++)
                std::cin >> q[j];
            std::cin >> m;
            for (int j = 1; j <= m; j++)
                pq.push(std::make_pair(0x3f3f3f3f, 0));
            query(rt);
            std::cout << "the closest " << m << " points are:\n";
            output();
        }
    }
    return 0;
}

void pushup(int x) {
    for (int i = 0; i < k; i++) {
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

void build(int &root, int l, int r, int d) {
    int mid = (l + r) >> 1;
    dime = d, root = mid;
    std::nth_element(a + l, a + mid, a + r + 1);
    for (int i = 0; i < k; i++)
        a[root].maxx[i] = a[root].minn[i] = a[root].d[i];
    if (l < mid)
        build(a[root].l, l, mid - 1, (d + 1) % k);
    if (r > mid)
        build(a[root].r, mid + 1, r, (d + 1) % k);
    pushup(root);
}

void output() {
    int x;
    while (!pq.empty()) {
        x = pq.top().second;
        pq.pop();
        output();
        for (int i = 0; i < k; i++)
            std::cout << a[x].d[i] << ' ';
        std::cout << '\n';
    }
}

inline long long dist(int x) {
    long long ret = 0;
    for (int i = 0; i < k; i++)
        ret += (long long)(q[i] - a[x].d[i]) * (q[i] - a[x].d[i]);
    return ret;
}

long long guess(int x) {
    long long s = 0;
    for (int i = 0; i < k; i++) {
        if (q[i] < a[x].minn[i])
            s += (long long)(q[i] - a[x].minn[i]) * (q[i] - a[x].minn[i]);
        if (q[i] > a[x].maxx[i])
            s += (long long)(q[i] - a[x].maxx[i]) * (q[i] - a[x].maxx[i]);
    }
    return s;
}

void query(int x) {
    if (!x)
        return;
    long long dis = dist(x), dl = guess(a[x].l), dr = guess(a[x].r);
    if (dis < pq.top().first) {
        pq.pop();
        pq.push(std::make_pair(dis, x));
    }
    if (dl < dr) {
        if (dl < pq.top().first)
            query(a[x].l);
        if (dr < pq.top().first)
            query(a[x].r);
    } else {
        if (dr < pq.top().first)
            query(a[x].r);
        if (dl < pq.top().first)
            query(a[x].l);
    }
}