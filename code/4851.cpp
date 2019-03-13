// 4851.cpp
#include <iostream>
#include <queue>

int const Maxn = 200010;
long long n, m, tot, ans = 0;
long long head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
long long son[Maxn], maxd[Maxn], top[Maxn], prt[Maxn], val[Maxn];
std::priority_queue<long long> q;

inline void add(long long x, long long y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs1(long long x);
void dfs2(long long x, long long tp);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> val[i];
    for (int i = 1, x, y; i < n; i++)
        std::cin >> x >> y, add(x, y);
    dfs1(1);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
        if (top[i] == i)
            q.push(maxd[i]);
    for (int i = 1; i <= m; i++) {
        ans += q.top();
        q.pop();
        if (q.empty())
            break;
    }
    std::cout << ans << '\n';
    return 0;
}

void dfs1(long long x) {
    maxd[x] = val[x];
    for (long long i = head[x]; i; i = Next[i]) {
        long long y = ver[i];
        if (y != prt[x]) {
            prt[y] = x;
            dfs1(y);
            maxd[x] = std::max(maxd[y] + val[x], maxd[x]);
            if (maxd[y] > maxd[son[x]])
                son[x] = y;
        }
    }
}

void dfs2(long long x, long long tp) {
    top[x] = tp;
    if (son[x])
        dfs2(son[x], tp);
    for (long long i = head[x]; i; i = Next[i]) {
        long long y = ver[i];
        if (y != prt[x] && y != son[x])
            dfs2(y, y);
    }
}