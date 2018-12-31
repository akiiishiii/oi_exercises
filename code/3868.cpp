// 3868.cpp
#include <algorithm>
#include <iostream>
#include <string>

int const Maxn = 300005;
int n, m, num = 0, root[Maxn * 5];

struct trie {
    int size, ch[2];
} tree[Maxn * 50];

int insert(int last, int x);
int query(int x, int y, int z);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    int all = 0;
    std::cin >> n >> m;
    n++;
    root[1] = insert(root[0], 0);
    for (int i = 2, x; i <= n; i++) {
        std::cin >> x;
        all ^= x;
        root[i] = insert(root[i - 1], all);
    }
    for (int i = 1, x, y, z; i <= m; i++) {
        std::cin >> s >> x;
        if (s[0] == 'A') {
            all ^= x;
            n++;
            root[n] = insert(root[n - 1], all);
        } else {
            std::cin >> y >> z;
            std::cout << query(root[x - 1], root[y], z ^ all) << '\n';
        }
    }
    return 0;
}

int insert(int last, int x) {
    int c = ++num, now = c, t;
    for (int i = 25; i >= 0; i--) {
        t = (x >> i) & 1;
        tree[now] = tree[last];
        tree[now].size++;
        last = tree[last].ch[t];
        tree[now].ch[t] = ++num;
        now = tree[now].ch[t];
    }
    tree[now].size = tree[last].size + 1;
    return c;
}

int query(int x, int y, int z) {
    int ret = 0;
    for (int i = 25; i >= 0; i--) {
        int l = (z >> i) & 1, r = l ^ 1;
        if (tree[tree[y].ch[r]].size - tree[tree[x].ch[r]].size > 0)
            ret += (1 << i), y = tree[y].ch[r], x = tree[x].ch[r];
        else
            y = tree[y].ch[l], x = tree[x].ch[l];
    }
    return ret;
}