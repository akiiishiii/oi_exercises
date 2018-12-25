// 4597.cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

struct node {
    int l, r, dis;
    int val;
} tree[1000010];
int pile[110], root[2], sum[110], g[110];

int merge(int x, int y);
int del(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, n, m;
    int hap = 0, wol = 0;
    std::string cmd;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= m; i++)
            std::cin >> pile[i];
        for (int i = 1, p, tot = 1; i <= m; i++) {
            for (int j = 1; j <= pile[i]; j++) {
                std::cin >> p;
                tree[tot].l = tree[tot].r = tree[tot].dis = 0;
                tree[tot].val = p;
                g[i] = merge(g[i], tot++);
            }
        }
        memset(sum, 0, sizeof(sum));
        root[0] = root[1] = 0;
        for (int i = 0, x, rra; i < n; i++) {
            std::cin >> cmd;
            if (cmd[0] == 'T') {
                std::cin >> x;
                root[i & 1] = merge(g[x], root[i & 1]);
                sum[i & 1] += pile[x];
                g[x] = pile[x] = 0;
            } else if (cmd[0] == 'C') {
                if (tree[root[0]].val > tree[root[1]].val) {
                    root[0] = merge(root[0], root[1]);
                    sum[0] += sum[1];
                    root[1] = sum[1] = 0;
                } else {
                    root[1] = merge(root[0], root[1]);
                    sum[1] += sum[0];
                    root[0] = sum[0] = 0;
                }
            } else if (cmd[0] == 'L') {
                root[i & 1] = del(root[i & 1]);
                sum[i & 1]--;
            } else if (cmd[0] == 'A') {
                std::cin >> x;
                tree[root[i & 1]].val += x;
            } else if (cmd[0] == 'E') {
                std::cin >> x;
                rra = del(root[i & 1]);
                tree[rra].val = x;
                root[i & 1] = merge(rra, root[i & 1]);
            }
            ((sum[0] > sum[1]) ? wol : hap)++;
        }
        std::cout << sum[0] << ':' << sum[1] << '\n';
    }
    std::cout << ((hap > wol) ? "I will be back!!\n" : "Hahaha...I win!!\n");
    return 0;
}

int merge(int x, int y) {
    if (!x)
        return y;
    if (!y)
        return x;
    if (tree[x].val < tree[y].val)
        std::swap(x, y);
    tree[x].r = merge(tree[x].r, y);
    if (tree[tree[x].l].dis < tree[tree[x].r].dis)
        std::swap(tree[x].l, tree[x].r);
    if (tree[x].r)
        tree[x].dis = tree[tree[x].r].dis + 1;
    else
        tree[x].dis = 0;
    return x;
}

int del(int x) {
    int l = tree[x].l, r = tree[x].r;
    tree[x].l = tree[x].r = tree[x].dis = 0;
    return merge(l, r);
}