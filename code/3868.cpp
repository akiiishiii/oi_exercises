// 3868.cpp
#include <algorithm>
#include <iostream>
#include <string>

int const Maxn = 300005;
int n, m, num = 0, root[Maxn * 5];

struct trie {
    int size, ch[2];
} tr[Maxn * 50];

int insert(int last, int x) {
    int c = ++num, now = c, t;
    for (int i = 25; i >= 0; i--) {
        t = (x >> i) & 1;
        tr[now] = tr[last];
        tr[now].size++;
        last = tr[last].ch[t];
        tr[now].ch[t] = ++num;
        now = tr[now].ch[t];
    }
    tr[now].size = tr[last].size + 1;
    return c;
}

int query(int x, int y, int z) {
    int ret = 0;
    for (int i = 25; i >= 0; i--) {
        int l = (z >> i) & 1, r = l ^ 1;
        if (tr[tr[y].ch[r]].size - tr[tr[x].ch[r]].size > 0)
            ret += (1 << i), y = tr[y].ch[r], x = tr[x].ch[r];
        else
            y = tr[y].ch[l], x = tr[x].ch[l];
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char s[10];
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