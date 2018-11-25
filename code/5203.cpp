// 5203.cpp
#include <iostream>

int const Maxn = 100010, Inf = 0x7fffffff;

struct Treap {
    int l, r;
    int val, dat;
    int cnt, size;
} tree[Maxn];

int tot, root, n;

int build(int val);
void update(int p) { tree[p].size = tree[tree[p].l].size + tree[tree[p].r].size + tree[p].cnt; }
int get_rank(int p, int val);
int get_val(int p, int rank);
void zig(int &p);
void zag(int &p);
void ins(int &p, int val);
int pre(int val);
int sec(int val);
void del(int &p, int val);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    build(-Inf), build(Inf);
    root = 1, tree[1].r = 2;
    update(root);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int opt, x;
        std::cin >> opt >> x;
        switch (opt) {
        case 1:
            ins(root, x);
            break;
        case 2:
            del(root, x);
            break;
        case 3:
            std::cout << get_rank(root, x) - 1 << '\n';
            break;
        case 4:
            std::cout << get_val(root, x + 1) << '\n';
            break;
        case 5:
            std::cout << pre(x) << '\n';
            break;
        case 6:
            std::cout << sec(x) << '\n';
            break;
        }
    }
}

int build(int val) {
    tree[++tot].val = val;
    tree[tot].dat = rand();
    tree[tot].cnt = tree[tot].size = 1;
    return tot;
}

int get_rank(int p, int val) {
    if (p == 0)
        return 0;
    if (val == tree[p].val)
        return tree[tree[p].l].size + 1;
    if (val < tree[p].val)
        return get_rank(tree[p].l, val);
    return get_rank(tree[p].r, val) + tree[tree[p].l].size + tree[p].cnt;
}

int get_val(int p, int rank) {
    if (p == 0)
        return Inf;
    if (tree[tree[p].l].size >= rank)
        return get_val(tree[p].l, rank);
    if (tree[tree[p].l].size + tree[p].cnt >= rank)
        return tree[p].val;
    return get_val(tree[p].r, rank - tree[tree[p].l].size - tree[p].cnt);
}

void zig(int &p) {
    int q = tree[p].l;
    tree[p].l = tree[q].r, tree[q].r = p, p = q;
    update(tree[p].r), update(p);
}

void zag(int &p) {
    int q = tree[p].r;
    tree[p].r = tree[q].l, tree[q].l = p, p = q;
    update(tree[p].l), update(p);
}

void ins(int &p, int val) {
    if (p == 0) {
        p = build(val);
        return;
    }
    if (val == tree[p].val) {
        tree[p].cnt++, update(p);
        return;
    }
    if (val < tree[p].val) {
        ins(tree[p].l, val);
        if (tree[p].dat < tree[tree[p].l].dat)
            zig(p);
    } else {
        ins(tree[p].r, val);
        if (tree[p].dat < tree[tree[p].r].dat)
            zag(p);
    }
    update(p);
}

int pre(int val) {
    int ans = 1;
    int p = root;
    while (p) {
        if (val == tree[p].val) {
            if (tree[p].l > 0) {
                p = tree[p].l;
                while (tree[p].r > 0)
                    p = tree[p].r;
                ans = p;
            }
            break;
        }
        if (tree[p].val < val && tree[p].val > tree[ans].val)
            ans = p;
        p = val < tree[p].val ? tree[p].l : tree[p].r;
    }
    return tree[ans].val;
}

int sec(int val) {
    int ans = 2;
    int p = root;
    while (p) {
        if (val == tree[p].val) {
            if (tree[p].r > 0) {
                p = tree[p].r;
                while (tree[p].l > 0)
                    p = tree[p].l;
                ans = p;
            }
            break;
        }
        if (tree[p].val > val && tree[p].val < tree[ans].val)
            ans = p;
        p = val < tree[p].val ? tree[p].l : tree[p].r;
    }
    return tree[ans].val;
}

void del(int &p, int val) {
    if (p == 0)
        return;
    if (val == tree[p].val) {
        if (tree[p].cnt > 1) {
            tree[p].cnt--, update(p);
            return;
        }
        if (tree[p].l || tree[p].r) {
            if (tree[p].r == 0 || tree[tree[p].l].dat > tree[tree[p].r].dat)
                zig(p), del(tree[p].r, val);
            else
                zag(p), del(tree[p].l, val);
            update(p);
        } else
            p = 0;
        return;
    }
    val < tree[p].val ? del(tree[p].l, val) : del(tree[p].r, val);
    update(p);
}