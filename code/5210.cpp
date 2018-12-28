// 5210.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 200010;
int n, m, num;
int c[Maxn], ret[Maxn];
struct node {
    int a, b, c;
    int cnt, ret;
} a[Maxn], p[Maxn];

bool cmp1(node const &x, node const &y);
bool cmp2(node const &x, node const &y);
inline int lowbit(int x) { return x & (-x); }
void add(int x, int d);
int ask(int x);
void cdq(int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int cnt = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].a >> a[i].b >> a[i].c;
    std::sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i <= n; i++) {
        cnt++;
        if (a[i].a != a[i + 1].a || a[i].b != a[i + 1].b ||
            a[i].c != a[i + 1].c) {
            p[++num] = a[i];
            p[num].cnt = cnt;
            cnt = 0;
        }
    }
    cdq(1, num);
    for (int i = 1; i <= num; i++)
        ret[p[i].ret + p[i].cnt - 1] += p[i].cnt;
    for (int i = 0; i < n; i++)
        std::cout << ret[i] << "\n";
    return 0;
}

bool cmp1(node const &x, node const &y) {
    return x.a < y.a || (x.a == y.a && x.b < y.b) ||
           (x.a == y.a && x.b == y.b && x.c < y.c);
}

bool cmp2(node const &x, node const &y) {
    return x.b < y.b || (x.b == y.b && x.c < y.c);
}

void add(int x, int d) {
    for (int i = x; i <= m; i += lowbit(i))
        c[i] += d;
    return;
}

int ask(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ret += c[i];
    return ret;
}

void cdq(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    std::sort(p + l, p + mid + 1, cmp2);
    std::sort(p + mid + 1, p + r + 1, cmp2);
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (p[i].b <= p[j].b) {
            add(p[i].c, p[i].cnt);
            i++;
        } else {
            p[j].ret += ask(p[j].c);
            j++;
        }
    }
    while (j <= r) {
        p[j].ret += ask(p[j].c);
        j++;
    }
    for (j = l; j < i; j++)
        add(p[j].c, -p[j].cnt);
}