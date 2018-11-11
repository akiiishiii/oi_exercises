// 1201.cpp
#include <iostream>
#include <string>

int const Maxn = 100005;

struct segment_tree {
    int a, b;
    int sum;
} tree[4 * Maxn + 5];

int ans = 0;

void build(int v, int l, int r);
void insert(int v, int l, int r);
void ask(int v, int x);

int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, command;
    std::cin >> n >> m;
    build(1, 1, n);
    for (int i = 1, x, y; i <= m; i++) {
        ans = 0;
        std::cin >> command >> x;
        if (command == 1) {
            std::cin >> y;
            insert(1, x, y);
        }
        else if (command == 2) {
            ask(1, x);
            std::cout << (ans & 1) << '\n';
        }
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

void insert(int v, int l, int r) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (l <= tree[v].a && r >= tree[v].b) {
        tree[v].sum += 1;
        return;
    }
    insert(v << 1, l, r);
    insert((v << 1) | 1, l, r);
}

void ask(int v, int x) {
    if (x > tree[v].b || x < tree[v].a)
        return;
    if (x >= tree[v].a && x <= tree[v].b) {
        ans += tree[v].sum;
    }
    if (tree[v].a == tree[v].b)
        return;
    ask(v << 1, x);
    ask((v << 1) | 1, x);
}