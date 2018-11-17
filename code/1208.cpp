// 1208.cpp
#include <iostream>

struct rectangle {
    int x1, y1;
    int x2, y2;
    int c;
} rect[101];

struct segmrnt_tree {
    int a, b;
    int c;
} tree[4 * 201 + 5];

int px[201] = {0}, ans[401] = {0};
bool lx[10001] = {false};

void build(int v, int l, int r) {
    tree[v].a = l;
    tree[v].b = r;
    tree[v].c = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

void insert(int v, int l, int r, int c) {
    if (l > tree[v].b || r < tree[v].a)
        return;
    if (tree[v].c > 0)
        return;
    if (l <= tree[v].a && r >= tree[v].b && tree[v].c != -1) {
        tree[v].c = c;
        return;
    }
    insert(v << 1, l, r, c);
    insert((v << 1) | 1, l, r, c);
    tree[v].c = -1;
}

void search(int v, int x) {
    if (!tree[v].c)
        return;
    if (tree[v].c > 0) {
        ans[tree[v].c] += (tree[v].b - tree[v].a + 1) * (px[x + 1] - px[x]);
        tree[v].c = 0;
        return;
    }
    search(v << 1, x);
    search((v << 1) | 1, x);
    tree[v].c = 0;
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, n;
    std::cin >> a >> b >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2 >> rect[i].c;
        lx[rect[i].x1] = true;
        lx[rect[i].x2] = true;
    }
    for (int i = 0; i <= a; i++)
        if (lx[i])
            px[++px[0]] = i;
    build(1, 0, b - 1);
    for (int i = 1; i < px[0]; i++) {
        for (int j = n; j >= 1; j--)
            if (rect[j].x1 <= px[i] && rect[j].x2 > px[i])
                insert(1, rect[j].y1, rect[j].y2 - 1, rect[j].c);
        search(1, i);
    }
    ans[1] = a * b;
    for (int i = 2; i <= 10000; i++)
        ans[1] -= ans[i];
    for (int i = 1; i <= 10000; i++)
        if (ans[i])
            std::cout << i << ' ' <<  ans[i] << '\n';
    return 0;
}