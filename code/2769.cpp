// 2769.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 200005;
int head[Maxn], ver[Maxn << 1], edge[Maxn << 1], Next[Maxn << 1];
int siz[Maxn], f[Maxn], pre[Maxn] = {0}, now[Maxn] = {0};
int flag, ret, n, k, m, ans, tot, cnt;
bool vis[Maxn], black[Maxn];

struct node {
    int son, len, dep;
    bool operator<(node const &n) const { return dep < n.dep; }
} tree[Maxn];

inline void add(int x, int y, int z);
int find_center(int x);
void tree_dp(int x, int prt, int root);
void dfs_siz(int x, int prt);
void dfs_num(int x, int prt, int sum, int num);
void dfs_len(int x, int prt, int dis, int num);
void dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x, y, z;
    std::cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> x;
        black[x] = true;
    }
    for (int i = 1; i < n; i++) {
        std::cin >> x >> y >> z;
        add(x, y, z), add(y, x, z);
    }
    dfs(1);
    std::cout << ans << '\n';
    return 0;
}

inline void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

int find_center(int x) {
    ret = 0x3f3f3f3f;
    dfs_siz(x, x);
    tree_dp(x, x, x);
    return flag;
}

void tree_dp(int x, int prt, int root) {
    f[x] = 0;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt || vis[y])
            continue;
        tree_dp(y, x, root);
        f[x] = std::max(f[x], siz[y]);
    }
    f[x] = std::max(f[x], siz[root] - siz[x]);
    if (f[x] < ret) {
        ret = f[x];
        flag = x;
    }
}

void dfs_siz(int x, int prt) {
    siz[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt || vis[y])
            continue;
        dfs_siz(y, x);
        siz[x] += siz[y];
    }
}

void dfs_num(int x, int prt, int sum, int num) {
    if (black[x])
        num++;
    if (num > k)
        return;
    if (num > tree[sum].dep)
        tree[sum].dep = num;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt || vis[y])
            continue;
        dfs_num(y, x, sum, num);
    }
}

void dfs_len(int x, int prt, int dis, int num) {
    if (black[x])
        num++;
    if (num > k)
        return;
    if (dis > now[num])
        now[num] = dis;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt || vis[y])
            continue;
        dfs_len(y, x, dis + edge[i], num);
    }
}

void dfs(int x) {
    int core, tmpk;
    core = find_center(x);
    vis[core] = true;
    cnt = 0;
    for (int i = head[core]; i; i = Next[i]) {
        int y = ver[i];
        if (vis[y])
            continue;
        tree[++cnt].dep = 0, tree[cnt].son = y, tree[cnt].len = edge[i];
        dfs_num(y, 0, cnt, 0);
    }
    std::sort(tree + 1, tree + cnt + 1);
    for (int i = 0; i <= tree[cnt].dep; i++)
        pre[i] = 0;
    for (int i = 1; i <= cnt; i++) {
        int y = tree[i].son;
        for (int j = 0; j <= tree[i].dep; j++)
            now[j] = 0xcfcfcfcf;
        dfs_len(y, 0, tree[i].len, 0);
        for (int j = 1; j <= tree[i].dep; j++)
            now[j] = std::max(now[j], now[j - 1]);
        for (int j = 0; j <= tree[i].dep; j++) {
            tmpk = std::min(tree[i - 1].dep, k - j - black[core]);
            if (tmpk < 0)
                continue;
            ans = std::max(ans, pre[tmpk] + now[j]);
        }
        for (int j = 0; j <= tree[i].dep; j++)
            pre[j] = std::max(pre[j], now[j]);
        for (int j = 1; j <= tree[i].dep; j++)
            pre[j] = std::max(pre[j - 1], pre[j]);
    }
    for (int i = head[core]; i; i = Next[i]) {
        int y = ver[i];
        if (!vis[y])
            dfs(y);
    }
}