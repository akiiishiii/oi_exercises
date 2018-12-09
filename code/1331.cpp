// 1331.cpp
#include <iostream>

int const SIZE = 50005;
int c[SIZE][2], prt[SIZE], mx[SIZE], v[SIZE], s[SIZE], t[SIZE], re[SIZE];
int n, m, root;

void pushup(int x);
void pushdown(int x);
void rotate(int x, int &f);
void splay(int x, int &f);
int find(int x, int k);
void add(int l, int r, int z);
void rev(int l, int r);
int maxx(int l, int r);
int build(int l, int r);

int main(int argc, char const *argv[]) {
    std::cin >> n >> m;
    root = build(1, n + 2);
    mx[0] = 0xcfcfcfcf;
    for (int i = 1, k, x, y, z; i <= m; i++) {
        std::cin >> k >> x >> y;
        if (k == 1) {
            std::cin >> z;
            add(x, y, z);
        } else if (k == 2)
            rev(x, y);
        else
            std::cout << maxx(x, y) << '\n';
    }
    return 0;
}

void pushup(int x) {
    int l = c[x][0], r = c[x][1];
    s[x] = s[l] + s[r] + 1;
    mx[x] = std::max(v[x], std::max(mx[l], mx[r]));
}

void pushdown(int x) {
    int l = c[x][0], r = c[x][1];
    if (t[x] != 0) {
        if (l) {
            mx[l] += t[x];
            v[l] += t[x];
            t[l] += t[x];
        }
        if (r) {
            mx[r] += t[x];
            v[r] += t[x];
            t[r] += t[x];
        }
        t[x] = 0;
    }
    if (re[x]) {
        re[x] = 0;
        re[l] ^= 1;
        re[r] ^= 1;
        std::swap(c[x][0], c[x][1]);
    }
}

void rotate(int x, int &f) {
    int y = prt[x], z = prt[y], l, r;
    l = (c[y][0] != x);
    r = l ^ 1;
    if (y == f)
        f = x;
    else {
        if (c[z][0] == y)
            c[z][0] = x;
        else
            c[z][1] = x;
    }
    prt[x] = z;
    prt[y] = x;
    prt[c[x][r]] = y;
    c[y][l] = c[x][r];
    c[x][r] = y;
    pushup(y);
    pushup(x);
}

void splay(int x, int &f) {
    while (x != f) {
        int y = prt[x], z = prt[y];
        if (y != f) {
            if (c[y][0] == x ^ c[z][0] == y)
                rotate(x, f);
            else
                rotate(y, f);
        }
        rotate(x, f);
    }
}

int find(int x, int k) {
    pushdown(x);
    int l = c[x][0], r = c[x][1];
    if (s[l] + 1 == k)
        return x;
    if (s[l] >= k)
        return find(l, k);
    return find(r, k - s[l] - 1);
}

void add(int l, int r, int z) {
    int x = find(root, l), y = find(root, r + 2);
    splay(x, root);
    splay(y, c[x][1]);
    t[x = c[y][0]] += z;
    v[x] += z;
    mx[x] += z;
}

void rev(int l, int r) {
    int x = find(root, l), y = find(root, r + 2);
    splay(x, root);
    splay(y, c[x][1]);
    re[c[y][0]] ^= 1;
}

int maxx(int l, int r) {
    int x = find(root, l), y = find(root, r + 2);
    splay(x, root);
    splay(y, c[x][1]);
    return mx[c[y][0]];
}

int build(int l, int r) {
    int mid = (l + r) / 2;
    if (l > r)
        return 0;
    c[mid][0] = build(l, mid - 1);
    if (c[mid][0])
        prt[c[mid][0]] = mid;
    c[mid][1] = build(mid + 1, r);
    if (c[mid][1])
        prt[c[mid][1]] = mid;
    pushup(mid);
    return mid;
}