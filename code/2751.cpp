// 2751.cpp
#include <cstring>
#include <iostream>

int const Maxn = 10003;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int vis[Maxn], vmy[Maxn], my[Maxn][505];
int tot = 0, n, m, mid, flag = 0;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
bool dfs(int u);
bool check();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y;
        add(i, x), add(i, y);
    }
    int l = 1, r = m;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check())
            r = mid - 1;
        else
            l = mid + 1;
    }
    std::cout << l << '\n';
    return 0;
}

bool dfs(int u) {
    for (int i = head[u]; i; i = Next[i]) {
        int y = ver[i];
        if (vis[y] != flag) {
            vis[y] = flag;
            if (vmy[y] < mid) {
                my[y][++vmy[y]] = u;
                return true;
            }
            for (int j = 1; j <= vmy[y]; j++)
                if (dfs(my[y][j])) {
                    my[y][j] = u;
                    return true;
                }
        }
    }
    return false;
}

bool check() {
    memset(my, 0, sizeof(my));
    memset(vmy, 0, sizeof(vmy));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i++) {
        flag++;
        if (!dfs(i))
            return false;
    }
    return true;
}