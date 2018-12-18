// 5265.cpp
#include <iostream>

int const Maxn = 1000010;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int l[Maxn], r[Maxn], s[Maxn], v[Maxn];
int tot, n, m, root, cnt;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m >> root;
    for (int i = 1; i <= n; i++)
        std::cin >> v[i];
    for (int i = 1, x, y; i < n; i++)
        std::cin >> x >> y, add(x, y), add(y, x);
    dfs(root, 0);
    for (int i = 1; i <= n; i++)
        s[l[i]] += v[i];
    for (int i = 1, cmd, a, x; i <= m; i++) {
        std::cin >> cmd >> a;
        if (cmd == 1) {
            std::cin >> x;
            for (int j = l[a]; j <= r[a]; j++)
                s[j] += x;
        } else {
            long long ans = 0;
            for (int j = l[a]; j <= r[a]; j++)
                ans += s[j];
            std::cout << ans << '\n';
        }
    }
    return 0;
}

void dfs(int x, int p) {
    l[x] = ++cnt;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        dfs(y, x);
    }
    r[x] = cnt;
}