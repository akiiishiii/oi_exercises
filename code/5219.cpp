// 5219.cpp
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

int const Maxn = 5010, Maxm = 500010;
int n, m, map[Maxn][Maxn];
int f[Maxn], siz[Maxn];
std::stack<std::pair<int, int>> st;
std::vector<int> g[Maxm << 2];

struct queries {
    int type, l, r, s, t;
} q[Maxm];

int search(int x) { return (x == f[x] ? x : f[x] = search(f[x])); }
void merge(int x, int y);
void undo(int k);
void add(int v, int l, int r, int ll, int rr, int x);
void solve(int v, int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, op, x, y; i <= m; i++) {
        std::cin >> op >> x >> y;
        if (x > y)
            std::swap(x, y);
        switch (op) {
        case 0:
            q[i].l = i, map[x][y] = i, q[i].s = x, q[i].t = y;
            break;
        case 1:
            q[map[x][y]].r = i;
            break;
        case 2:
            q[i].type = 1, q[i].s = x, q[i].t = y;
            break;
        default:
            break;
        }
    }
    for (int i = 1; i <= n; i++)
        f[i] = i, siz[i] = 1;
    for (int i = 1; i <= m; i++)
        if (q[i].l && !q[i].r)
            q[i].r = m + 1;
    for (int i = 1; i <= m; i++)
        if (q[i].l)
            add(1, 1, m, q[i].l, q[i].r - 1, i);
    solve(1, 1, m);
    return 0;
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

void undo(int k) {
    while (st.size() > k) {
        std::pair<int, int> t = st.top();
        st.pop();
        f[t.first] = t.first;
        siz[t.second] -= siz[t.first];
    }
}

void add(int v, int l, int r, int ll, int rr, int d) {
    if (ll <= l && r <= rr) {
        g[v].push_back(d);
        return;
    }
    int mid = (l + r) >> 1;
    if (ll <= mid)
        add(v << 1, l, mid, ll, rr, d);
    if (rr > mid)
        add((v << 1) | 1, mid + 1, r, ll, rr, d);
}

void solve(int v, int l, int r) {
    int tp = st.size();
    for (int i = 0; i < g[v].size(); i++)
        merge(q[g[v][i]].s, q[g[v][i]].t);
    if (l == r) {
        if (q[l].type == 1)
            std::cout << (search(q[l].s) == search(q[l].t) ? 'Y' : 'N') << '\n';
    } else {
        int mid = (l + r) >> 1;
        solve(v << 1, l, mid);
        solve((v << 1) | 1, mid + 1, r);
    }
    undo(tp);
}