#include <iostream>

using namespace std;
const int N = 200005;
int n, h[N], cnt, tot, m[N][2], fa[N], si[N], d[N], mx[N], mn[N];
bool fl, v[N];

void dfs(int u) {
    if (u > n) {
        mn[u] = d[u], mx[u] = d[u];
        return;
    }
    for (int i = 0; i <= 1; i++) {
        d[m[u][i]] = d[u] + 1;
        dfs(m[u][i]);
        si[u] += si[m[u][i]];
    }
    mn[u] = min(mn[m[u][0]], mn[m[u][1]]);
    mx[u] = max(mx[m[u][0]], mx[m[u][1]]);
    if (mn[u] != mx[u])
        v[u] = 1;
    if (v[m[u][0]] && v[m[u][1]])
        fl = 1;
}
int wk(int u) {
    if (u > n)
        return 0;
    return (si[m[u][1]] > si[m[u][0]]) + wk(m[u][0]) + wk(m[u][1]);
}
int main() {
    in >> n;
    tot = n;
    for (int i = 1; i <= n; i++) {
        in >> m[i][0] >> m[i][1];
        if (m[i][0] == -1)
            m[i][0] = ++tot, si[m[i][0]] = 1;
        if (m[i][1] == -1)
            m[i][1] = ++tot, si[m[i][1]] = 1;
    }
    d[1] = 1;
    dfs(1);
    if (mx[1] - mn[1] > 1 || fl) {
        out << "-1\n";
        return 0;
    }
    out << wk(1) << '\n';
    return 0;
}