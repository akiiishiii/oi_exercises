// 1299.cpp
#include <iostream>
#include <algorithm>

int const Maxn = 200010;

int s, w, n, cnt;
int ans[10010], c[2000010];

struct dat {
    int x, y, z;
    int pos, id;
    bool operator<(dat const &d) const;
    dat() = default;
    dat(int dx, int dy, int dz, int p, int dn = n) : x(dx), y(dy), z(dz), pos(p), id(dn) {}
} a[Maxn], b[Maxn];

inline int lowbit(int const x) { return x & (-x); }
void add(int x, int v);
int query(int x);
inline void cdq(int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y, z, x1, y1, x2, y2;
    std::cin >> s >> w;
    while (true) {
        int opt;
        std::cin >> opt;
        if (opt == 1) {
            std::cin >> x >> y >> z;
            n++;
            a[n] = dat(x,y,z,0);
        } else if (opt == 2) {
            std::cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--;
            ans[++cnt] = (x2 - x1) * (y2 - y1) * s;
            n++;
            a[n] = dat(x1, y1, 1, cnt);
            n++;
            a[n] = dat(x1, y2, -1, cnt);
            n++;
            a[n] = dat(x2, y1, -1, cnt);
            n++;
            a[n] = dat(x2, y2, 1, cnt);
        } else
            break;
    }
    std::sort(a + 1, a + n + 1);
    cdq(1, n);
    for (int i = 1; i <= cnt; i++)
        std::cout << ans[i] << '\n';
    return 0;
}

bool dat::operator<(dat const &d) const {
    if (x == d.x && y == d.y)
        return pos < d.pos;
    else if (x == d.x)
        return y < d.y;
    else
        return x < d.x;
}

void add(int x, int v) {
    for (int i = x; i <= w; i += lowbit(i))
        c[i] += v;
}

int query(int x) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i))
        ret += c[i];
    return ret;
}

inline void cdq(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) >> 1, l1 = l, l2 = mid + 1;
    for (int i = l; i <= r; i++) {
        if (a[i].id <= mid && !a[i].pos)
            add(a[i].y, a[i].z);
        if (a[i].id > mid && a[i].pos)
            ans[a[i].pos] += query(a[i].y) * a[i].z;
    }
    for (int i = l; i <= r; i++)
        if (a[i].id <= mid && !a[i].pos)
            add(a[i].y, -a[i].z);
    for (int i = l; i <= r; i++) {
        if (a[i].id <= mid)
            b[l1++] = a[i];
        else
            b[l2++] = a[i];
    }
    for (int i = l; i <= r; i++)
        a[i] = b[i];
    cdq(l, mid);
    cdq(mid + 1, r);
}