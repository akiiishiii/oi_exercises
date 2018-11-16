// 1205.cpp
#include <iostream>

int const Maxn = 200005;

struct segment_tree {
    int a, b;
    int color;
} tree[4 * Maxn + 5];

bool color[Maxn >> 1] = {false};

void build(int v, int l, int r);
void insert(int v, int l, int r, int c);
void search(int v);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int l, r, n, d;
    std::cin >> l >> r >> n;
    d = -l;
    build(1, l + d, r + d - 1);
    for (int i = 1, bl, br; i <= n; i++) {
        std::cin >> bl >> br;
        insert(1, bl + d, br + d - 1, i);
    }
    search(1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += color[i];
    std::cout << ans << '\n';
    return 0;
}

void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    tree[v].color = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void insert(int v, int l, int r, int c) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (l <= tree[v].a && r >= tree[v].b) {
        tree[v].color = c;
        return;
    }
    if (tree[v].color >= 0) {
        tree[v << 1].color = tree[(v << 1) | 1].color = tree[v].color;
        tree[v].color = -1;
    }
    insert(v << 1, l, r, c);
    insert((v << 1) | 1, l, r, c);
}

void search(int v) {
    if (tree[v].color > 0)
        color[tree[v].color] = true;
    else if (tree[v].color == -1) {
        search(v << 1);
        search((v << 1) | 1);
    }
}