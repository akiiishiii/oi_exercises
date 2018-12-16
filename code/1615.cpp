// 1615.cpp
#include <iostream>
#include <string>

int const Mod = 51061, Maxn = 1000005;
int top;
int c[Maxn][2], prt[Maxn], size[Maxn], q[Maxn];
bool rev[Maxn];
long long sum[Maxn], val[Maxn], at[Maxn], mt[Maxn];

void cal(int x, int m, int a);
inline bool isroot(int x) { return c[prt[x]][0] != x && c[prt[x]][1] != x; }
void pushup(int x);
void pushdown(int x);
void rot(int x);
void splay(int x);
void access(int x);
void evert(int x);
void split(int x, int y);
void link(int x, int y);
void cut(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n, u, v, c;
    std::string ch;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        val[i] = sum[i] = mt[i] = size[i] = 1;
    for (int i = 1; i < n; i++)
        std::cin >> u >> v, link(u, v);
    while (m--) {
        std::cin >> ch >> u >> v;
        switch (ch[0]) {
        case '+':
            std::cin >> c;
            split(u, v);
            cal(u, 1, c);
            break;
        case '-':
            cut(u, v);
            std::cin >> u >> v;
            link(u, v);
            break;
        case '*':
            std::cin >> c;
            split(u, v);
            cal(u, c, 0);
            break;
        case '/':
            split(u, v);
            std::cout << sum[u] << '\n';
            break;
        }
    }
    return 0;
}

void cal(int x, int m, int a) {
    if (!x)
        return;
    val[x] = (val[x] * m + a) % Mod;
    sum[x] = (sum[x] * m + a * size[x]) % Mod;
    at[x] = (at[x] * m + a) % Mod;
    mt[x] = (mt[x] * m) % Mod;
}

void pushup(int x) {
    int l = c[x][0], r = c[x][1];
    sum[x] = (sum[l] + sum[r] + val[x]) % Mod;
    size[x] = (size[l] + size[r] + 1) % Mod;
}

void pushdown(int x) {
    int l = c[x][0], r = c[x][1];
    if (rev[x]) {
        rev[x] ^= 1;
        rev[l] ^= 1;
        rev[r] ^= 1;
        std::swap(c[x][0], c[x][1]);
    }
    int m = mt[x], a = at[x];
    mt[x] = 1;
    at[x] = 0;
    if (m != 1 || a != 0)
        cal(l, m, a), cal(r, m, a);
}

void rot(int x) {
    int y = prt[x], z = prt[y], l, r;
    l = (c[y][1] == x);
    r = l ^ 1;
    if (!isroot(y))
        c[z][c[z][1] == y] = x;
    prt[x] = z;
    prt[y] = x;
    prt[c[x][r]] = y;
    c[y][l] = c[x][r];
    c[x][r] = y;
    pushup(y);
    pushup(x);
}

void splay(int x) {
    q[++top] = x;
    for (int i = x; !isroot(i); i = prt[i])
        q[++top] = prt[i];
    while (top)
        pushdown(q[top--]);
    while (!isroot(x)) {
        int y = prt[x], z = prt[y];
        if (!isroot(y))
            rot(((c[y][0] == x) ^ (c[z][0] == y)) ? x : y);
        rot(x);
    }
}

void access(int x) {
    for (int t = 0; x; t = x, x = prt[x]) {
        splay(x);
        c[x][1] = t;
        pushup(x);
    }
}

void evert(int x) {
    access(x);
    splay(x);
    rev[x] ^= 1;
}

void split(int x, int y) {
    evert(y);
    access(x);
    splay(x);
}

void link(int x, int y) {
    evert(x);
    prt[x] = y;
}

void cut(int x, int y) {
    split(y, x);
    c[y][0] = prt[x] = 0;
}