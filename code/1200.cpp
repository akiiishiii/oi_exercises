// 1200.cpp
#include <iostream>
#include <string>

int const Maxn = 100005;

struct segment_tree {
    int a, b;
    int sum;
} tree[4 * Maxn + 5];

void build(int v, int l, int r);
void insert(int v, int x, int d);
int ask(int v, int l, int r);

int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::string command;
    std::cin >> n >> m;
    build(1, 1, n);
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> command >> x >> y;
        if (command[1] == 'd')
            insert(1, x, y);
        else if (command[1] == 'u')
            insert(1, x, -y);
        else
            std::cout << ask(1, x, y) << '\n';
    }
    return 0;
}

void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    tree[v].sum = 0;
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void insert(int v, int x, int d) {
    if (tree[v].a > x || tree[v].b < x)
        return;
    if (tree[v].a == tree[v].b) {
        tree[v].sum += d;
        return;
    }
    insert(v << 1, x, d);
    insert((v << 1) | 1, x, d);
    tree[v].sum = tree[v << 1].sum + tree[(v << 1) | 1].sum;
}

int ask(int v, int l, int r) {
    if(tree[v].a > r || tree[v].b < l)
        return 0;
    if(tree[v].a >= l && tree[v].b <= r)
        return tree[v].sum;
    return ask(v << 1, l, r) + ask((v << 1) | 1, l, r);
}