// 1141.cpp
#include <iostream>

int const Maxn = 1000005;
int ver[2 * Maxn], edge[2 * Maxn], Next[2 * Maxn], head[Maxn], indeg[Maxn],
    c[Maxn], q[2 * Maxn];
long long f[Maxn], d[Maxn], a[2 * Maxn], b[2 * Maxn], ans;
bool v[Maxn];
int n, m, tot;

void add(int x, int y, int z);
void bfs(int s, int t);
void topsort();
void dp(int t, int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        std::cin >> x >> y;
        add(i, x, y), add(x, i, y);
    }
    for (int i = 1, x = 0; i <= n; i++)
        if (!c[i])
            bfs(i, ++x);
    topsort();
    for (int i = 1; i <= n; i++)
        if (indeg[i] > 1 && !v[c[i]]) {
            v[c[i]] = true;
            dp(c[i], i);
            ans += d[c[i]];
        }
    std::cout << ans << '\n';
    return 0;
}

void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
    indeg[y]++;
}

void bfs(int s, int t) {
    int l = 1, r = 1;
    q[1] = s, c[s] = t;
    while (l <= r) {
        for (int i = head[q[l]]; i; i = Next[i])
            if (!c[ver[i]])
                q[++r] = ver[i], c[ver[i]] = t;
        l++;
    }
}

void topsort() {
    int l = 1, r = 0, x, y;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 1)
            q[++r] = i;
    while (l <= r) {
        for (int i = head[x = q[l]]; i; i = Next[i])
            if (indeg[y = ver[i]] > 1) {
                d[c[x]] = std::max(d[c[x]], f[x] + f[y] + edge[i]);
                f[y] = std::max(f[y], f[x] + edge[i]);
                if ((--indeg[y]) == 1)
                    q[++r] = y;
            }
        l++;
    }
}

void dp(int t, int x) {
    int m = 0, l = 0, r, y = x;
    {
        int i;
        do {
            a[++m] = f[y];
            indeg[y] = 1;
            for (i = head[y]; i; i = Next[i])
                if (indeg[ver[i]] > 1) {
                    y = ver[i];
                    b[m + 1] = b[m] + edge[i];
                    break;
                }
        } while (i);
    }
    if (m == 2) {
        for (int i = head[y]; i; i = Next[i])
            if (ver[i] == x)
                l = std::max(l, edge[i]);
        d[t] = std::max(d[t], f[x] + f[y] + l);
        return;
    }
    for (int i = head[y]; i; i = Next[i])
        if (ver[i] == x) {
            b[m + 1] = b[m] + edge[i];
            break;
        }
    for (int i = 1; i < m; i++) {
        a[m + i] = a[i];
        b[m + i] = b[m + 1] + b[i];
    }
    q[l = r = 1] = 1;
    for (int i = 2; i < 2 * m; i++) {
        while (l <= r && i - q[l] >= m)
            l++;
        d[t] = std::max(d[t], a[i] + a[q[l]] + b[i] - b[q[l]]);
        while (l <= r && a[q[r]] + b[i] - b[q[r]] <= a[i])
            r--;
        q[++r] = i;
    }
}