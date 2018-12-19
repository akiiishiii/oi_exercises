// 5265.cpp
#include <cmath>
#include <cstring>
#include <iostream>

int const Maxn = 1000010;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int l[Maxn], r[Maxn], s[Maxn], v[Maxn];
int d[Maxn], prt[Maxn], f[Maxn][20];
long long c1[Maxn], c2[Maxn], v2[Maxn];
int tot, n, m, root, cnt;

template <typename T> inline T lowbit(T const x) { return x & (-x); }
void add(long long c[], int x, long long d);
long long sum(long long c[], int x);
inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x, int p, int depth);
void st();
int lca(int a, int b);
template <typename T> inline void read(T &x);
template <typename T> inline void write(T x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    read(n), read(m), read(root);
    add(root, n + 1), add(n + 1, root);
    for (int i = 1; i <= n; i++)
        read(v[i]);
    for (int i = 1, x, y; i < n; i++)
        read(x), read(y), add(x, y), add(y, x);
    dfs(n + 1, 0, 0);
    st();
    for (int i = 1, cmd, a, b, dlca; i <= m; i++) {
        long long x;
        read(cmd), read(a);
        if (cmd == 1) {
            read(b), read(x);
            dlca = lca(a, b);
            add(c1, l[a], x), add(c1, l[b], x);
            add(c1, l[dlca], -x), add(c1, l[prt[dlca]], -x);
            add(c2, l[a], x * d[a]), add(c2, l[b], x * d[b]);
            add(c2, l[dlca], -x * d[dlca]);
            add(c2, l[prt[dlca]], -x * d[prt[dlca]]);
        } else if (cmd == 2)
            write(v[a] + sum(c1, r[a]) - sum(c1, l[a] - 1)),
                std::cout.put('\n');
        else
            write(v2[a] + sum(c2, r[a]) - sum(c2, l[a] - 1) -
                  (d[a] - 1) * (sum(c1, r[a]) - sum(c1, l[a] - 1))),
                std::cout.put('\n');
    }
    return 0;
}

void add(long long c[], int x, long long d) {
    for (int i = x; i <= n + 1; i += lowbit(i))
        c[i] += d;
}

long long sum(long long c[], int x) {
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}

void dfs(int x, int p, int depth) {
    d[x] = depth, l[x] = ++cnt, prt[x] = p, v2[x] = v[x];
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dfs(y, x, depth + 1);
        v2[x] += v2[y];
    }
    r[x] = cnt;
}

void st() {
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[i][0] = prt[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (f[i][j - 1] != -1)
                f[i][j] = f[f[i][j - 1]][j - 1];
}

int lca(int a, int b) {
    int k;
    if (d[a] < d[b])
        std::swap(a, b);
    k = int(log2(d[a]));
    for (int i = k; i >= 0; i--)
        if (d[a] - (1 << i) >= d[b])
            a = f[a][i];
    if (a == b)
        return b;
    for (int i = k; i >= 0; i--)
        if (f[a][i] != -1 && f[a][i] != f[b][i]) {
            a = f[a][i];
            b = f[b][i];
        }
    return f[a][0];
}

template <typename T> inline void read(T &x) {
    int d = 1;
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9') {
        if (c == '-')
            d = -1;
        c = std::cin.get();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
    x *= d;
}

template <typename T> inline void write(T x) {
    T y = 10;
    int len = 1;
    if (x < 0)
        std::cout.put('-'), x = -x;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        std::cout.put(x / y + 48);
        x %= y;
    }
}