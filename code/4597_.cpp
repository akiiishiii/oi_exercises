// 4597.cpp
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define M 1000010

struct node {
    int l, r, dis;
    int val;
} tree[M];
int g[110];

int merge(int x, int y) {
    if (!x)
        return y;
    if (!y)
        return x;
    if (tree[x].val < tree[y].val)
        swap(x, y);
    tree[x].r = merge(tree[x].r, y);
    if (tree[tree[x].l].dis < tree[tree[x].r].dis)
        swap(tree[x].l, tree[x].r);
    if (tree[x].r)
        tree[x].dis = tree[tree[x].r].dis + 1;
    else
        tree[x].dis = 0;
    return x;
}

int pop(int x) {
    int l = tree[x].l, r = tree[x].r;
    tree[x].l = tree[x].r = tree[x].dis = 0;
    return merge(l, r);
}

int main(int argc, char *argv[]) {
    int T, n, m;
    int pile[110], root[2], sum[110], tot;
    char op[5];
    int Happy = 0, Wolffy = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &pile[i]);
        }
        tot = 1;
        for (int i = 1, p; i <= m; ++i) {
            for (int j = 1; j <= pile[i]; ++j) {
                scanf("%d", &p);
                tree[tot].l = tree[tot].r = tree[tot].dis = 0;
                tree[tot].val = p;
                g[i] = merge(g[i], tot);
                tot++;
            }
        }
        memset(sum, 0, sizeof(sum));
        root[0] = root[1] = 0;
        for (int i = 0, x, rra; i < n; ++i) {
            scanf("%s", &op);
            if (op[0] == 'T') {
                scanf("%d", &x);
                root[i & 1] = merge(g[x], root[i & 1]);
                sum[i & 1] += pile[x];
                g[x] = 0;
                pile[x] = 0;
            } else if (op[0] == 'C') {
                if (tree[root[0]].val > tree[root[1]].val) {
                    root[0] = merge(root[0], root[1]);
                    sum[0] += sum[1];
                    root[1] = 0;
                    sum[1] = 0;
                } else {
                    root[1] = merge(root[0], root[1]);
                    sum[1] += sum[0];
                    root[0] = 0;
                    sum[0] = 0;
                }
            } else if (op[0] == 'L') {
                root[i & 1] = pop(root[i & 1]);
                sum[i & 1]--;
            } else if (op[0] == 'A') {
                scanf("%d", &x);
                tree[root[i & 1]].val += x;
            } else if (op[0] == 'E') {
                scanf("%d", &x);
                rra = pop(root[i & 1]);
                tree[rra].val = x;
                root[i & 1] = merge(rra, root[i & 1]);
            }
        }
        printf("%d:%d\n", sum[0], sum[1]);
        if (sum[0] > sum[1]) {
            Wolffy++;
        } else {
            Happy++;
        }
    }
    if (Happy > Wolffy) {
        printf("I will be back!!\n");
    } else {
        printf("Hahaha...I win!!\n");
    }
    return 0;
}
