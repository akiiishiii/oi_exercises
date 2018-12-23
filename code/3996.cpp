// 3996.cpp
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

int const K = 2;
int dime, m;
long long ans[25];

struct point {
    long long x[2], minn[2], maxx[2];
    int id;
    bool operator<(point const &b) const;
} p[100010], a[200010], bj[25], now;

inline void pushup(int x, int y);
void build(int x, int l, int r, int dep);
inline long long dis(point a, point b);
void query(int x, int l, int r, int dep);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, T;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < K; j++) {
            std::cin >> p[i].x[j];
            p[i].id = i;
            p[i].maxx[j] = p[i].minn[j] = p[i].x[j];
        }
    build(1, 1, n, 0);
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        std::cin >> now.x[0] >> now.x[1];
        std::cin >> m;
        for (int i = 1; i <= m; i++)
            ans[i] = -1;
        query(1, 1, n, 0);
        std::cout << bj[m].id << '\n';
    }
    return 0;
}

bool point::operator<(point const &b) const {
    return x[dime] < b.x[dime] || (x[dime] == b.x[dime] && id > b.id);
}

inline void pushup(int x, int y) {
    a[x].minn[0] = std::min(a[x].minn[0], a[y].minn[0]);
    a[x].maxx[0] = std::max(a[x].maxx[0], a[y].maxx[0]);
    a[x].minn[1] = std::min(a[x].minn[1], a[y].minn[1]);
    a[x].maxx[1] = std::max(a[x].maxx[1], a[y].maxx[1]);
}

void build(int x, int l, int r, int dep) {
    dime = dep % K;
    int mid = (l + r) >> 1;
    std::nth_element(p + l, p + mid, p + r + 1);
    a[x] = p[mid];
    if (l == r)
        return;
    if (l <= mid - 1) {
        build(x << 1, l, mid - 1, dep + 1);
        pushup(x, x << 1);
    }
    if (r >= mid + 1) {
        build((x << 1) ^ 1, mid + 1, r, dep + 1);
        pushup(x, (x << 1) ^ 1);
    }
}

inline long long dis(point a, point b) {
    return (a.x[0] - b.x[0]) * (a.x[0] - b.x[0]) +
           (a.x[1] - b.x[1]) * (a.x[1] - b.x[1]);
}

void query(int x, int l, int r, int dep) {
    dime = dep % K;
    long long x0 = std::max(
                  (now.x[0] - a[x].maxx[0]) * (now.x[0] - a[x].maxx[0]),
                  (now.x[0] - a[x].minn[0]) * (now.x[0] - a[x].minn[0])),
              x1 = std::max(
                  (now.x[1] - a[x].maxx[1]) * (now.x[1] - a[x].maxx[1]),
                  (now.x[1] - a[x].minn[1]) * (now.x[1] - a[x].minn[1]));
    if (x0 + x1 < ans[m])
        return;
    long long tmp = dis(a[x], now);
    for (int i = 1; i <= m; i++)
        if (tmp > ans[i] || (tmp == ans[i] && a[x].id < bj[i].id)) {
            for (int j = m; j >= i + 1; j--) {
                ans[j] = ans[j - 1];
                bj[j] = bj[j - 1];
            }
            ans[i] = tmp;
            bj[i] = a[x];
            break;
        }
    int mid = (l + r) >> 1;
    if (now < a[x]) {
        if (r >= mid + 1)
            query((x << 1) ^ 1, mid + 1, r, dep + 1);
        if (l <= mid - 1)
            query(x << 1, l, mid - 1, dep + 1);
    } else {
        if (l <= mid - 1)
            query(x << 1, l, mid - 1, dep + 1);
        if (r >= mid + 1)
            query((x << 1) ^ 1, mid + 1, r, dep + 1);
    }
}