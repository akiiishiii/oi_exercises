// 3918.cpp
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

int const K = 2;
int q[3], dime;
std::priority_queue<std::pair<long long, int>> pq;
struct point {
    int d[3];
    int maxx[3], minn[3];
    int l, r;
    bool operator<(point const &x) const { return d[dime] < x.d[dime]; }
} a[110]; //[600010];

void pushup(int x);
void build(int &root, int l, int r, int d);
inline long long dist(int x);
long long guess(int x);
void query(int x);
void insert(int root, int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t, n, m, rt;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < K; j++)
            std::cin >> a[i].d[j];
    build(rt, 1, n, 0);
    for (int i = 1; i <= m; i++) {
        std::cin >> t;
        for (int j = 0; j < K; j++)
            std::cin >> q[j];
        if (t == 2) {
            pq.push(std::make_pair(0x3f3f3f3f3f3f3f3f, 0));
            query(rt);
            std::cout << dist(pq.top().second) << '\n';
            while (pq.size())
                pq.pop();
        } else {
            n++;
            for (int j = 0; j < K; j++)
                a[n].maxx[i] = a[n].minn[i] = a[n].d[j] = q[j];
            insert(rt, n);
        }
    }
    return 0;
}

void pushup(int x) {
    for (int i = 0; i < K; i++) {
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
    for (int i = 0; i < K; i++)
        a[root].maxx[i] = a[root].minn[i] = a[root].d[i];
    if (l < mid)
        build(a[root].l, l, mid - 1, d ^ 1);
    if (r > mid)
        build(a[root].r, mid + 1, r, d ^ 1);
    pushup(root);
}

inline long long dist(int x) {
    long long ret = 0;
    for (int i = 0; i < K; i++)
        ret += llabs((long long)(q[i] - a[x].d[i]));
    return ret;
}

long long guess(int x) {
    long long s = 0;
    for (int i = 0; i < K; i++) {
        if (q[i] < a[x].minn[i])
            s += llabs((long long)(q[i] - a[x].minn[i]));
        if (q[i] > a[x].maxx[i])
            s += llabs((long long)(q[i] - a[x].maxx[i]));
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

void insert(int root, int x) {
    int dir = 0, p = root;
    while (true) {
        for (int i = 0; i < K; i++) {
            a[p].maxx[i] = std::max(a[p].maxx[i], a[x].maxx[i]);
            a[p].minn[i] = std::min(a[p].minn[i], a[x].minn[i]);
        }
        if (a[x].d[dir] >= a[p].d[dir]) {
            if (!a[p].r) {
                a[p].r = x;
                return;
            } else
                p = a[p].r;
        } else {
            if (!a[p].l) {
                a[p].l = x;
                return;
            } else
                p = a[p].l;
        }
        dir ^= 1;
    }
}