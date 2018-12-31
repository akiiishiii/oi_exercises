// 3875.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

int const Maxn = 100010;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int depth[Maxn], poww[25], prt[Maxn][25], root[Maxn * 5];
int val[Maxn];
int n, m, tot = 0, cnt = 1, num = 0;

struct trie {
    int size, ch[2];
} tree[Maxn * 30];

inline void add(int x, int y) { ver[++cnt] = y, Next[cnt] = head[x], head[x] = cnt; }
int insert(int last, int x);
void dfs(int x, int p, int d);
void st();
int lca(int x, int y);
int query(int x, int y, int p, int z);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    poww[0] = 1;
    for (int i = 1; i <= 20; i++)
        poww[i] = poww[i - 1] * 2;
    while (std::cin >> n >> m) {
        cnt = 1, num = 0, tot = 0;
        memset(head, 0, sizeof(head));
        memset(depth, 0, sizeof(depth));
        memset(prt, 0, sizeof(prt));
        memset(tree, 0, sizeof(tree));
        memset(root, 0, sizeof(root));
        for (int i = 1; i <= n; i++)
            std::cin >> val[i];
        for (int i = 1, x, y; i <= n - 1; i++)
            std::cin >> x >> y, add(x, y), add(y, x);
        dfs(1, 0, 1);
        st();
        for (int i = 1, x, y, z; i <= m; i++) {
            std::cin >> x >> y >> z;
            int p = lca(x, y);
            std::cout << std::max(query(root[x], root[y], root[p], z),
                                  z ^ val[p])
                      << '\n';
        }
    }
    return 0;
}

int insert(int last, int x) {
    int now, c = ++num, t;
    now = c;
    for (int i = 15; i >= 0; i--) {
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

void dfs(int x, int p, int d) {
    depth[x] = d;
    prt[x][0] = p;
    root[x] = insert(root[p], val[x]);
    for (int i = head[x]; i; i = Next[i]) {
        int t = ver[i];
        if (t == p)
            continue;
        dfs(t, x, d + 1);
    }
}

void st() {
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
            if (prt[i][j - 1])
                prt[i][j] = prt[prt[i][j - 1]][j - 1];
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        std::swap(x, y);
    int t = depth[x] - depth[y];
    for (int i = 0; poww[i] <= t; i++)
        if (t & poww[i])
            x = prt[x][i];
    for (int i = 20; i >= 0; i--)
        if (prt[x][i] != prt[y][i])
            x = prt[x][i], y = prt[y][i];
    if (x == y)
        return y;
    return prt[x][0];
}

int query(int x, int y, int p, int z) {
    int ans = 0, l, r;
    for (int i = 15; i >= 0; i--) {
        l = (z >> i) & 1;
        r = 1 - l;
        if (tree[tree[x].ch[r]].size + tree[tree[y].ch[r]].size -
                2 * tree[tree[p].ch[r]].size >
            0)
            ans += (1 << i), x = tree[x].ch[r], y = tree[y].ch[r],
                             p = tree[p].ch[r];
        else
            x = tree[x].ch[l], y = tree[y].ch[l], p = tree[p].ch[l];
    }
    return ans;
}