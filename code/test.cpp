#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <stack>

int const Maxn = 5005, Maxm = 500005;

struct Union_Find_Set {
    int f[Maxn], siz[Maxn], top;
    std::stack<std::pair<int, int>> st;
    void reset(int n) {
        for (int i = 1; i <= n; i++) {
            f[i] = i;
            siz[i] = 1;
        }
    }
    int search(int x) {
        return (x == f[x] ? x : f[x] = search(f[x]));
    }
    void merge(int x, int y) {
        x = search(x), y = search(y);
        if (x == y)
            return;
        if (siz[x] > siz[y])
            std::swap(x, y);
        st.push(std::make_pair(x, y));
        siz[y] += siz[x];
        f[x] = y;
    }
    bool is_connect(int x, int y) {
        x = search(x), y = search(y);
        return x == y;
    }
    void undo(int k) {
        while (top > k) {
            std::pair<int, int> t = st.top();
            st.pop()
            f[t.first] = t.first;
            siz[t.second] -= siz[t.first];
        }
    }
} f;
struct queries {
    int type, l, r, s, t;
} q[Maxm];

int n, m, mp[5005][5005];
std::vector<int> v[Maxm << 2];
void Add(int p, int l, int r, int L, int R, int x) {
    if (L <= l && r <= R) {
        v[p].push_back(x);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid)
        Add(p << 1, l, mid, L, R, x);
    if (R > mid)
        Add(p << 1 | 1, mid + 1, r, L, R, x);
}
void Solve(int p, int l, int r) {
    int siz = v[p].size(), tp = f.top;
    for (int i = 0; i < siz; i++) {
        int s = q[v[p][i]].s, t = q[v[p][i]].t;
        f.merge(s, t);
    }
    if (l == r) {
        if (q[l].type == 1) {
            if (f.is_connect(q[l].s, q[l].t))
                puts("Y");
            else
                puts("Maxn");
        }
    } else {
        int mid = (l + r) >> 1;
        Solve(p << 1, l, mid);
        Solve(p << 1 | 1, mid + 1, r);
    }
    f.undo(tp);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int tp, x, y;
        scanf("%d%d%d", &tp, &x, &y);
        if (x > y)
            std::swap(x, y);
        if (tp == 0) {
            q[i].l = i, mp[x][y] = i;
            q[i].s = x, q[i].t = y;
        }
        if (tp == 1) {
            q[mp[x][y]].r = i;
        }
        if (tp == 2) {
            q[i].type = 1;
            q[i].s = x, q[i].t = y;
        }
    }
    f.reset(n);
    for (int i = 1; i <= m; i++)
        if (q[i].l && !q[i].r)
            q[i].r = m + 1;
    for (int i = 1; i <= m; i++)
        if (q[i].l)
            Add(1, 1, m, q[i].l, q[i].r - 1, i);
    Solve(1, 1, m);
    return 0;
}