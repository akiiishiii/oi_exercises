// 2716_.cpp
#include <iostream>
#include <string>
#include <cstring>

int const Maxn = 30005;
int c[Maxn][2], prt[Maxn], val[Maxn], sum[Maxn], max[Maxn];
bool aux[Maxn], rev[Maxn];
int head[Maxn], Next[Maxn << 1], ver[Maxn << 1];
int tot;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void rot(int x);
void splay(int x);
void pushup(int x) { sum[x] = val[x] + sum[c[x][0]] + sum[c[x][1]], max[x] = std::max(val[x], std::max(max[c[x][0]], max[c[x][1]])); }
void pushdown(int x);
void access(int x);
void addrev(int x);
int findroot(int x);
void evert(int x);
void cut(int x, int y);
void link(int x, int y);
void split(int x, int y);
void insert(int x, int y);
void dfslink(int x, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(max, 0xcf, sizeof(max));
    int n, q;
    std::string opt;
    std::cin >> n;
    for (int i = 1, a, b; i < n; i++)
        std::cin >> a >> b, add(a, b), add(b, a);
    dfslink(1, 0);
    for (int i = 1; i <= n; i++)
        std::cin >> val[i];
    std::cin >> q;
    for (int i = 1, x, y; i <= q; i++) {
        std::cin >> opt >> x >> y;
        switch (opt[1]) {
        case 'M':
            split(x, y);
            std::cout << max[y] << '\n';
            break;
        case 'S':
            split(x, y);
            std::cout << sum[y] << '\n';
            break;
        case 'H':
            insert(x, y);
            break;
        default:
            break;
        }
    }
    return 0;
}

void rot(int x) {
    int y = prt[x], z = prt[y], l, r;
    l = (c[y][0] != x), r = (l ^ 1);
    if (aux[y]) {
        if (c[z][0] == y)
            c[z][0] = x;
        else
            c[z][1] = x;
    } else
        aux[y] = true, aux[x] = false;
    prt[x] = z, prt[y] = x, prt[c[x][r]] = y;
    c[y][l] = c[x][r], c[x][r] = y;
    pushup(y), pushup(x);
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
        addrev(c[x][0]);
        addrev(c[x][1]);
    }
}

void access(int x) {
    int y = 0;
    while (x) {
        splay(x);
        aux[c[x][1]] = false;
        aux[y] = true;
        c[x][1] = y;
        pushup(x);
        y = x;
        x = prt[x];
    }
}

void addrev(int x) {
    std::swap(c[x][0], c[x][1]);
    rev[x] ^= 1;
}

int findroot(int x) {
    access(x);
    splay(x);
    while (c[x][0])
        x = c[x][0];
    return x;
}

void evert(int x) {
    access(x);
    splay(x);
    addrev(x);
}

void cut(int x, int y) {
    split(x, y);
    if (c[y][0] == x) {
        prt[x] = c[y][0] = 0;
        aux[x] = false;
    }
}

void link(int x, int y) {
    evert(y);
    prt[y] = x;
}

void split(int x, int y) {
    evert(x);
    access(y);
    splay(y);
}

void insert(int x, int y) {
    access(x);
    splay(x);
    val[x] = y;
    pushup(x);
}

void dfslink(int x, int p) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dfslink(y, x);
        link(x, y);
    }
}