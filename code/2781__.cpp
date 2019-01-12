// 2781__.cpp
#include <iostream>
#include <string>

int const Maxn = 50010, Maxm = 10010;

struct query {
    int x, y;
    int type, id;
    int k;
    query() = default;
    ~query() = default;
    query(int _x, int _y, int _type, int _id, int _k = 0) : x(_x), y(_y), type(_type), id(_id), k(_k) {}
};

query q[(Maxn + Maxm) << 1], q1[(Maxn + Maxm) << 1], q2[(Maxn + Maxm) << 1];
int t[Maxn], ans[Maxn], a[Maxn];
int n, m, tot, totx;

inline int lowbit(int const &x) { return x & (-x); }
void add(int x, int z);
void divide(int ql, int qr, int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    char s[5];
    for (int i = 1, x; i <= n; i++)
        std::cin >> x, a[i] = x, q[++tot] = query(x, 1, 1, i);
    for (int i = 1, x, y, k; i <= m; i++) {
        std::cin >> s;
        if (s[0] == 'Q')
            std::cin >> x >> y >> k, q[++tot] = query(x, y, 2, ++totx, k);
        else {
            std::cin >> x >> y, q[++tot] = query(a[x], -1, 1, x);
            a[x] = y, q[++tot] = query(y, 1, 1, x);
        }
    }
    divide(1, tot, 0, 0x3f3f3f3f);
    for (int i = 1; i <= totx; i++)
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
                add(q[i].id, q[i].y);
                q1[t1++] = q[i];
            } else
                q2[t2++] = q[i];
        } else {
            int tt = ask(q[i].y) - ask(q[i].x - 1);
            if (tt >= q[i].k)
                q1[t1++] = q[i];
            else {
                q[i].k -= tt;
                q2[t2++] = q[i];
            }
        }
    }
    for (int i = 0; i < t1; i++)
        q[ql + i] = q1[i];
    for (int i = 0; i < t2; i++)
        q[ql + t1 + i] = q2[i];
    for (int i = 0; i < t1; i++)
        if (q1[i].type == 1)
            add(q1[i].id, -q1[i].y);
    divide(ql, ql + t1 - 1, l, mid);
    divide(ql + t1, qr, mid + 1, r);
}