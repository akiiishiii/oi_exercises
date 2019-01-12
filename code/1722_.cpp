// 1722_.cpp
#include <iostream>

int const Maxn = 100010, Maxm = 10010;

struct query {
    int x, type, id;
    int y, k;
    query() = default;
    ~query() = default;
    query(int _x, int _type, int _id, int _y = 0, int _k = 0) : x(_x), type(_type), id(_id), y(_y), k(_k) {}
};

query q[Maxn + Maxm], q1[Maxn + Maxm], q2[Maxn + Maxm];
int t[Maxn], ans[Maxn];
int n, m, tot = 0;

inline int lowbit(int const &x) { return x & (-x); }
void add(int x, int z);
void divide(int ql, int qr, int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x; i <= n; i++)
        std::cin >> x, q[++tot] = query(x, 1, i);
    for (int i = 1, x, y, k; i <= m; i++)
        std::cin >> x >> y >> k, q[++tot] = query(x, 2, i, y, k);
    divide(1, tot, 0xcfcfcfcf, 0x3f3f3f3f);
    for (int i = 1; i <= m; i++)
        std::cout << ans[i] << '\n';
    return 0;
}

void add(int x, int z) {
    for (int i = x; i <= n; i += lowbit(i))
        t[i] += z;
}

int ask(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ret += t[i];
    return ret;
}

void divide(int ql, int qr, int l, int r) {
    if (ql > qr)
        return;
    if (l == r) {
        for (int i = ql; i <= qr; i++)
            if (q[i].type == 2)
                ans[q[i].id] = l;
        return;
    }
    int mid = (l + r) >> 1, t1 = 0, t2 = 0;
    for (int i = ql; i <= qr; i++) {
        if (q[i].type == 1) {
            if (q[i].x <= mid) {
                add(q[i].id, 1);
                q1[++t1] = q[i];
            } else
                q2[++t2] = q[i];
        } else {
            int tt = ask(q[i].y) - ask(q[i].x - 1);
            if (tt >= q[i].k)
                q1[++t1] = q[i];
            else {
                q[i].k -= tt;
                q2[++t2] = q[i];
            }
        }
    }
    for (int i = 1; i <= t1; i++)
        if (q1[i].type == 1)
            add(q1[i].id, -1);
    for (int i = 1; i <= t1; i++)
        q[ql + i - 1] = q1[i];
    for (int i = 1; i <= t2; i++)
        q[ql + t1 + i - 1] = q2[i];
    divide(ql, ql + t1 - 1, l, mid);
    divide(ql + t1, qr, mid + 1, r);
}