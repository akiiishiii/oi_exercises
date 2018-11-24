// 2571.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

int const Maxn = 105;

struct atp {
    int data, pro;
    int cnt;
    int l, r;
    int ln, rn;
} tree[Maxn];

int tot = 0, root = 0;

void turnleft(int &p);
void turnright(int &p);
void ins(int &p, int x);
void del(int &p, int x);
int find(int p, int x);
int find_k(int p, int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    srand((unsigned)time(NULL));
    int n, m;
    std::cin >> n >> m;
    for (int i = 1, x, p, d = 0; i <= m; i++) {
        char c;
        std::cin >> c >> x;
        switch (c) {
        case 'i':
            if (!find(root, x))
                ins(root, x);
            break;
        case 'd':
            p = tree[find_k(root, tot - d - x + 1)].data;
            std::cout << p << '\n';
            del(root, p);
            d++;
            break;
        default:
            break;
        }
    }
    return 0;
}

void turnleft(int &p) {
    int t = tree[p].r;
    tree[p].r = tree[t].l;
    tree[t].l = p;
    tree[p].rn = tree[t].ln;
    tree[t].ln = tree[p].ln + tree[p].rn + 1;
    p = t;
}

void turnright(int &p) {
    int t = tree[p].l;
    tree[p].l = tree[t].r;
    tree[t].r = p;
    tree[p].ln = tree[t].rn;
    tree[t].rn = tree[p].ln + tree[p].rn + 1;
    p = t;
}

void ins(int &p, int x) {
    if (!p) {
        p = ++tot;
        tree[p].data = x;
        tree[p].cnt = 1;
        tree[p].l = tree[p].r = tree[p].ln = tree[p].rn = 0;
        tree[p].pro = rand() % 10000;
        return;
    }
    if (x <= tree[p].data) {
        ins(tree[p].l, x);
        tree[p].ln++;
        if (tree[tree[p].l].pro < tree[p].pro)
            turnright(p);
    } else {
        ins(tree[p].r, x);
        tree[p].rn++;
        if (tree[tree[p].r].pro < tree[p].pro)
            turnleft(p);
    }
}

void del(int &p, int x) {
    if (p) {
        if (x < tree[p].data) {
            tree[p].ln--;
            del(tree[p].l, x);
        } else if (x > tree[p].data) {
            tree[p].rn--;
            del(tree[p].r, x);
        } else {
            if (!(tree[p].l || tree[p].r)) {
                p = 0;
                return;
            }
            int lp = 0x3f3f3f3f, rp = 0x3f3f3f3f;
            if (tree[p].l)
                lp = tree[tree[p].l].pro;
            if (tree[p].r)
                rp = tree[tree[p].r].pro;
            if (lp <= rp) {
                turnright(p);
                tree[p].rn--;
                del(tree[p].r, x);
            } else {
                turnleft(p);
                tree[p].ln--;
                del(tree[p].l, x);
            }
        }
    }
}

int find(int p, int x) {
    if (p) {
        if (x == tree[p].data)
            return p;
        else if (x < tree[p].data)
            return find(tree[p].l, x);
        else
            return find(tree[p].r, x);
    } else
        return 0;
}

int find_k(int p, int k) {
    if (tree[p].ln + tree[p].rn + 1 < k)
        return 0;
    else if (tree[p].ln + 1 == k)
        return p;
    if (k <= tree[p].ln)
        return find_k(tree[p].l, k);
    else
        return find_k(tree[p].r, k - tree[p].ln - 1);
}