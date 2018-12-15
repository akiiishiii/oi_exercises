// 3175.cpp
#include <iostream>

int const Maxn = 300005;
int c[Maxn][2], prt[Maxn], val[Maxn], size[Maxn];
bool aux[Maxn], rev[Maxn];

void rot(int x);
void splay(int x);
void pushup(int x) { size[x] = 1 + size[c[x][0]] + size[c[x][1]]; }
void pushdown(int x);
void access(int x);
void addrev(int x);
int findroot(int x);
void evert(int x);
void cut(int x, int y);
void link(int x, int y);
void split(int x, int y);
void insert(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> val[i], link(i, (i + val[i] <= n) ? (i + val[i]) : (n + 1));
    std::cin >> m;
    for (int i = 1, x, y, z; i <= m; i++) {
        std::cin >> x >> y;
        y++;
        if (x == 1) {
            split(y, n + 1);
            std::cout << size[n + 1] - 1 << '\n';
        } else if (x == 2) {
            std::cin >> z;
            cut(y, (y + val[y] <= n) ? (y + val[y]) : (n + 1));
            link(y, (y + z <= n) ? (y + z) : (n + 1));
            val[y] = z;
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
