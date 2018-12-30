// 4548.cpp
#include <algorithm>
#include <cmath>
#include <iostream>

int const Maxn = 100010;

int n, k, cnt, top;
int c[Maxn << 1], ans[Maxn];

struct query {
    int a, b, c;
    int sum, num;
    bool operator<(query const &q) const { return b == q.b ? c < q.c : b < q.b; }
    bool operator!=(query const &q) const { return a != q.a || b != q.b || c != q.c; }
} s[Maxn], q[Maxn];

bool cmp(query const &a, query const &b);
inline int lowbit(int x) { return x & (-x); }
void add(int x, int d);
int sum(int x);
void cdq(int l, int r);

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> s[i].a >> s[i].b >> s[i].c;
    std::sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cnt++;
        if (s[i] != s[i + 1]) {
            q[++top] = s[i];
            q[top].num = cnt;
            cnt = 0;
        }
    }
    cdq(1, top);
    for (int i = 1; i <= top; i++)
        ans[q[i].sum + q[i].num - 1] += q[i].num;
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << '\n';
    return 0;
}

bool cmp(query const &a, query const &b) {
    if (a.a == b.a && a.b == b.b)
        return a.c < b.c;
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}

void add(int x, int d) {
    for (int i = x; i <= k; i += lowbit(i))
        c[i] += d;
}

int sum(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ret += c[i];
    return ret;
}

void cdq(int l, int r) {
    int mid = (l + r) >> 1;
    if (l == r)
        return;
    cdq(l, mid);
    cdq(mid + 1, r);
    std::sort(q + l, q + mid + 1);
    std::sort(q + mid + 1, q + r + 1);
    int tp1 = l;
    for (int i = mid + 1; i <= r; i++) {
        while (tp1 <= mid && q[tp1].b <= q[i].b)
            add(q[tp1].c, q[tp1].num), tp1++;
        q[i].sum += sum(q[i].c);
    }
    for (int i = l; i < tp1; i++)
        add(q[i].c, -q[i].num);
}