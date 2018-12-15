// 2869.cpp
#include <iostream>
#include <string>

int const Maxn = 100010;
int c[Maxn][2], prt[Maxn], v[Maxn], ls[Maxn], rs[Maxn], num[Maxn], bj[Maxn];
bool rev[Maxn], aux[Maxn];

void pushdown(int x);
void pushup(int x);
void rot(int x);
void splay(int x);
void access(int x);
int findroot(int x);
void evert(int x);
void cut(int x, int y);
void link(int x, int y);
void split(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::string opt;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
        rs[i] = ls[i] = v[i];
        num[i] = 1;
    }
    for (int i = 1, x, y; i < n; i++)
        std::cin >> x >> y, link(x, y);
    for (int i = 1, x, y, z; i <= m; i++) {
        std::cin >> opt >> x >> y;
        if (opt[0] == 'Q') {
            split(x, y);
            std::cout << num[y] << '\n';
        } else {
            std::cin >> z;
            split(x, y);
            bj[y] = z;
        }
    }
    return 0;
}

void pushdown(int x) {
    if (rev[x]) {
        std::swap(c[x][0], c[x][1]);
        std::swap(rs[x], ls[x]);
        rev[c[x][0]] ^= 1;
        rev[c[x][1]] ^= 1;
        rev[x] = 0;
    }
    if (bj[x]) {
        bj[c[x][1]] = bj[c[x][0]] = rs[x] = ls[x] = bj[x];
        num[x] = 1;
        v[x] = bj[x];
        bj[x] = 0;
    }
}

void pushup(int x) {
    if (c[x][0])
        pushdown(c[x][0]);
    if (c[x][1])
        pushdown(c[x][1]);
    num[x] = num[c[x][1]] + num[c[x][0]] + 1;
    if (rs[c[x][0]] == v[x])
        num[x]--;
    if (ls[c[x][1]] == v[x])
        num[x]--;
    if (c[x][0])
        ls[x] = ls[c[x][0]];
    else
        ls[x] = v[x];
    if (c[x][1])
        rs[x] = rs[c[x][1]];
    else
        rs[x] = v[x];
}

void rot(int x) {
    int y = prt[x], z = prt[y], l, r;
    l = (c[y][0] != x);
    r = l ^ 1;
    if (aux[y]) {
        if (c[z][0] == y)
            c[z][0] = x;
        else
            c[z][1] = x;
    } else {
        aux[y] = 1;
        aux[x] = 0;
    }
    prt[x] = z;
    prt[y] = x;
    prt[c[x][r]] = y;
    c[y][l] = c[x][r];
    c[x][r] = y;
    pushup(y);
    pushup(x);
}

void splay(int x) {
    pushdown(x);
    while (aux[x]) {
        int y = prt[x], z = prt[y];
        if (aux[y])
            pushdown(z);
        pushdown(y);
        pushdown(x);
        if (aux[y])
            rot(((c[y][0] == x) ^ (c[z][0] == y)) ? x : y);
        rot(x);
    }
}

void access(int x) {
    int y = 0;
    while (x) {
        splay(x);
        aux[c[x][1]] = 0;
        aux[y] = 1;
        c[x][1] = y;
        prt[y] = x;
        y = x;
        pushup(x);
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
    split(x, y);
    prt[c[y][0]] = 0;
    aux[c[y][0]] = 0;
    c[y][0] = 0;
}

void link(int x, int y) {
    evert(x);
    prt[x] = y;
}

void split(int x, int y) {
    evert(x);
    access(y);
    splay(y);
}