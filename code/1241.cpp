// 1241.cpp
#include <iostream>

struct splay_tree {
    int data;
    int prt, l, r;
    int cnt;
    int ln, rn;
} tree[200005];

int root = 0, tot = 0;

void zig(int x);
void zag(int x);
void splay(int x);
int find(int x);
int find_k(int k);
void ins(int x);
void del(int x);
int max(int r);
int min(int r);
int pre(int x);
int suc(int x);
void output(int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 1, k; i <= n; i++) {
        std::cin >> k;
        int p = find(k);
        if (p == -1)
            ins(k);
        else
            tree[p].cnt++;
    }
    output(root);
    return 0;
}

void zig(int x) {
    int y = tree[x].prt;
    tree[y].l = tree[x].r;
    if (tree[x].r)
        tree[tree[x].r].prt = y;
    tree[x].prt = tree[y].prt;
    if (tree[y].prt) {
        if (y == tree[tree[y].prt].l)
            tree[tree[y].prt].l = x;
        else
            tree[tree[y].prt].r = x;
    }
    tree[x].r = y;
    tree[y].prt = x;
    tree[y].ln = tree[x].rn;
    tree[x].rn = tree[y].ln + tree[y].rn + 1;
}

void zag(int x) {
    int y = tree[x].prt;
    tree[y].r = tree[x].l;
    if (tree[x].l)
        tree[tree[x].l].prt = y;
    tree[x].prt = tree[y].prt;
    if (tree[y].prt) {
        if (y == tree[tree[y].prt].l)
            tree[tree[y].prt].l = x;
        else
            tree[tree[y].prt].r = x;
    }
    tree[x].l = y;
    tree[y].prt = x;
    tree[y].rn = tree[x].ln;
    tree[x].ln = tree[y].ln + tree[y].rn + 1;
}

void splay(int x) {
    int p;
    while (tree[x].prt) {
        p = tree[x].prt;
        if (!tree[p].prt) {
            if (x == tree[p].l)
                zig(x);
            else
                zag(x);
            break;
        }
        if (x == tree[p].l) {
            if (p == tree[tree[p].prt].l)
                zig(p), zig(x);
            else
                zig(x), zag(x);
        } else {
            if (p == tree[tree[p].prt].r)
                zag(p), zag(x);
            else
                zag(x), zig(x);
        }
    }
    root = x;
}

int find(int x) {
    int p = root;
    while (p) {
        if (x == tree[p].data) {
            splay(p);
            return p;
        } else if (x < tree[p].data)
            p = tree[p].l;
        else
            p = tree[p].r;
    }
    return -1;
}

int find_k(int k) {
    int p = root;
    if (tree[p].ln + tree[p].rn + 1 < k)
        return -1;
    while (true) {
        if (tree[p].rn + 1 == k)
            return tree[p].data;
        if (tree[p].rn >= k)
            p = tree[p].r;
        else
            k = k - tree[p].rn - 1, p = tree[p].l;
    }
}

void ins(int x) {
    int p = root, f;
    while (p) {
        f = p;
        if (x <= tree[p].data) {
            tree[p].ln++;
            p = tree[p].l;
        } else {
            tree[p].rn++;
            p = tree[p].r;
        }
    }
    tree[++tot].data = x;
    tree[tot].cnt = 1;
    tree[tot].prt = tree[tot].l = tree[tot].r = tree[tot].ln = tree[tot].rn = 0;
    if (!root) {
        root = tot;
        return;
    }
    tree[tot].prt = f;
    if (x <= tree[f].data)
        tree[f].l = tot;
    else
        tree[f].r = tot;
    splay(tot);
}

void del(int x) {
    find(x);
    int p = root;
    int ls = tree[p].l, rs = tree[p].r;
    if (!(ls || rs)) {
        root = 0;
        return;
    }
    if (!ls) {
        root = rs;
        tree[rs].prt = 0;
        return;
    }
    if (!rs) {
        root = ls;
        tree[ls].prt = 0;
        return;
    }
    p = ls;
    tree[ls].prt = 0;
    while (tree[p].r)
        p = tree[p].r;
    splay(p);
    tree[p].r = rs, tree[rs].prt = p;
    tree[p].rn = tree[rs].ln + tree[rs].rn + 1;
}

int max(int r) {
    int p = r;
    while (tree[p].r)
        p = tree[p].r;
    return tree[p].data;
}

int min(int r) {
    int p = r;
    while (tree[p].l)
        p = tree[p].l;
    return tree[p].data;
}

int pre(int x) {
    find(x);
    int p = tree[root].l;
    while (tree[p].r)
        p = tree[p].r;
    return p ? tree[p].data : -1;
}

int suc(int x) {
    find(x);
    int p = tree[root].r;
    while (tree[p].l)
        p = tree[p].l;
    return p ? tree[p].data : -1;
}

void output(int r) {
    if (tree[r].l)
        output(tree[r].l);
    std::cout << tree[r].data << ' ' << tree[r].cnt << '\n';
    if (tree[r].r)
        output(tree[r].r);
}