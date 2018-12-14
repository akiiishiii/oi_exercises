// 2821.cpp
#include <iostream>
#include <string>

int const Maxn = 10005;
int c[Maxn][2], prt[Maxn], aux[Maxn], rev[Maxn];

void rot(int x);
void splay(int x);
void pushdown(int x);
void access(int x);
int findroot(int x);
void evert(int x);
void cut(int x, int y);
void link(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, u, v;
    std::string s;
    std::cin >> n >> m;
    while (m--) {
        std::cin >> s >> u >> v;
        switch (s[0]) {
        case 'C':
            link(u, v);
            break;
        case 'D':
            cut(u, v);
            break;
        case 'Q':
            std::cout << ((findroot(u) == findroot(v)) ? "Yes\n" : "No\n");
            break;
        default:
            break;
        }
    }
    return 0;
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