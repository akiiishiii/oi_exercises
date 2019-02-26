// 2525and2399.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int const Maxn = 1200010, Maxm = 1000010, Maxq = 100010;
int ans[Maxq], vis[Maxm];
int c[Maxn][2], prt[Maxn], aux[Maxn], rev[Maxn];
int p[Maxn], cp[Maxn][2], val[Maxn], maxx[Maxn], maxid[Maxn];
std::vector<int> ids[Maxq], tos[Maxq];
int n, m, cnt, tot, id, qq;

struct edge {
    int u, v, w;
    bool operator<(edge const &x) const { return w < x.w; }
} e[Maxn];

struct query {
    int op, x, y, w;
} q[Maxq];

void pushup(int x);
void rot(int x);
void splay(int x);
void pushdown(int x);
void access(int x);
int findroot(int x);
void evert(int x);
void cut(int x, int y);
void link(int x, int y);
int getmax(int x, int y);
int search(int x) { return (p[x] == x ? x : p[x] = search(p[x])); }
void kruskal();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> qq;
    cnt = n;
    for (int i = 1; i <= n; i++)
        val[i] = maxx[i] = 0, maxid[i] = i;
    for (int i = 1; i <= m; i++) {
        std::cin >> e[i].u >> e[i].v >> e[i].w;
        if (e[i].u > e[i].v)
            std::swap(e[i].u, e[i].v);
        tos[e[i].u].push_back(e[i].v);
        ids[e[i].u].push_back(i);
    }
    for (int i = 1; i <= qq; i++) {
        std::cin >> q[i].op >> q[i].x >> q[i].y;
        if (q[i].x > q[i].y)
            std::swap(q[i].x, q[i].y);
        if (q[i].op == 2) {
            for (int j = 0; j < tos[q[i].x].size(); j++)
                if (tos[q[i].x][j] == q[i].y) {
                    vis[ids[q[i].x][j]] = true;
                    q[i].w = e[ids[q[i].x][j]].w;
                    break;
                }
        }
    }
    for (int i = 1; i <= m; i++)
        if (!vis[i])
            e[++tot] = e[i];
    kruskal();
    for (int i = qq; i; i--) {
        if (q[i].op == 1)
            ans[++ans[0]] = getmax(q[i].x, q[i].y);
        else {
            int maxd = getmax(q[i].x, q[i].y);
            if (maxd > q[i].w) {
                cut(id, cp[id][0]), cut(id, cp[id][1]);
                cnt++;
                val[cnt] = maxx[cnt] = q[i].w;
                maxid[cnt] = cnt;
                link(cnt, q[i].x), link(cnt, q[i].y);
                cp[cnt][0] = q[i].x, cp[cnt][1] = q[i].y;
            }
        }
    }
    for (int i = ans[0]; i >= 1; i--)
        std::cout << ans[i] << '\n';
    return 0;
}

void pushup(int x) {
    if (maxx[c[x][0]] > maxx[c[x][1]]) {
        maxx[x] = maxx[c[x][0]];
        maxid[x] = maxid[c[x][0]];
    } else {
        maxx[x] = maxx[c[x][1]];
        maxid[x] = maxid[c[x][1]];
    }
    if (val[x] > maxx[x]) {
        maxx[x] = val[x];
        maxid[x] = x;
    }
}

void rot(int x) {
    int y = prt[x], z = prt[y], l, r;
    l = (c[y][0] != x), r = l ^ 1;
    if (aux[y]) {
        if (c[z][0] == y)
            c[z][0] = x;
        else
            c[z][1] = x;
    } else
        aux[y] = true, aux[x] = false;
    prt[x] = z, prt[y] = x, prt[c[x][r]] = y;
    c[y][l] = c[x][r], c[x][r] = y;
    pushup(y);
    pushup(x);
}

void splay(int x) {
    pushdown(x);
    while (aux[x]) {
        int y = prt[x], z = prt[y];
        if (aux[y])
            pushdown(z);
        pushdown(y), pushdown(x);
        if (aux[y])
            rot(((c[y][0] == x) ^ (c[z][0] == y)) ? x : y);
        rot(x);
    }
}

void pushdown(int x) {
    if (rev[x]) {
        rev[x] = false;
        std::swap(c[x][0], c[x][1]);
        rev[c[x][0]] ^= 1;
        rev[c[x][1]] ^= 1;
    }
}

void access(int x) {
    int y = 0;
    while (x) {
        splay(x);
        aux[c[x][1]] = false;
        aux[y] = true;
        c[x][1] = y;
        prt[y] = x;
        pushup(x);
        y = x;
        x = prt[x];
    }
}

int findroot(int x) {
    access(x);
    splay(x);
    while (c[x][0]) {
        pushdown(x);
        x = c[x][0];
    }
    return x;
}

void evert(int x) {
    access(x);
    splay(x);
    rev[x] ^= 1;
}

void cut(int x, int y) {
    evert(x);
    access(y);
    splay(y);
    prt[c[y][0]] = 0;
    aux[c[y][0]] = false;
    c[y][0] = 0;
}

void link(int x, int y) {
    evert(y);
    prt[y] = x;
}

int getmax(int x, int y) {
    evert(x);
    access(y);
    splay(y);
    id = maxid[y];
    return maxx[y];
}

void kruskal() {
    std::sort(e + 1, e + tot + 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int num = 0;
    for (int i = 1; i <= tot; i++) {
        int f1 = search(e[i].u), f2 = search(e[i].v);
        if (f1 != f2) {
            p[f1] = f2;
            num++, cnt++;
            val[cnt] = maxx[cnt] = e[i].w;
            maxid[cnt] = cnt;
            link(cnt, e[i].u), link(cnt, e[i].v);
            cp[cnt][0] = e[i].u, cp[cnt][1] = e[i].v;
        }
        if (num == n - 1)
            break;
    }
}