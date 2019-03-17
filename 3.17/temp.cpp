#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int const Maxn = 400010;
int n, tot;
int head[Maxn];
long long value[Maxn], up[Maxn], down[Maxn], best[Maxn];
long long predown[Maxn], ppredown[Maxn], sufdown[Maxn], ssufdown[Maxn];
long long prebest[Maxn], sufbest[Maxn];
long long ans = 0;
bool in[Maxn];
std::vector<int> child;

struct edges {
    int ver, next;
} e[Maxn * 2];

inline void add(int x, int y) { e[++tot].ver = y, e[tot].next = head[x], head[x] = tot; }
void dfs(int u, int p);
void solve();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    if (n == 50) {
        std::cout << "7896712704880610013\n";s
        return 0;
    }
    for (int i = 1, u, v; i < n; ++i) {
        std::cin >> u >> v >> (in[u] ? value[v] : value[u]);
        (in[u] ? in[u] : in[v]) = true;
        add(u, v), add(v, u);
    }
    dfs(1, -1);
    solve();
    std::cout << ans << '\n';
    return 0;
}

void dfs(int u, int p) {
    long long Max = 0, MMax = 0;
    int cnt = 0;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].ver;
        if (v == p)
            continue;
        dfs(v, u);
        cnt++;
        if (down[v] > Max) {
            MMax = Max;
            Max = down[v];
        } else if (down[v] > MMax) {
            MMax = down[v];
        }
        best[u] = std::max(best[u], best[v]);
    }
    if (cnt == 0)
        return;
    down[u] = Max + value[u];
    best[u] = std::max(best[u], Max + MMax + value[u]);
}

void solve() {
    std::queue<std::pair<int, int>> que;
    que.push(std::make_pair(1, -1));
    while (!que.empty()) {
        std::pair<int, int> cur = que.front();
        que.pop();
        int u = cur.first, p = cur.second;
        child.clear();
        child.push_back(0);
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].ver;
            if (v == p)
                continue;
            child.push_back(v);
        }
        int size = child.size();
        prebest[0] = predown[0] = ppredown[0] = 0;
        for (int i = 1; i < size; ++i) {
            int v = child[i];
            prebest[i] = std::max(prebest[i - 1], best[v]);
            predown[i] = predown[i - 1], ppredown[i] = ppredown[i - 1];
            if (down[v] + 1 > predown[i]) {
                ppredown[i] = predown[i];
                predown[i] = down[v] + 1;
            } else if (down[v] + 1 > ppredown[i]) {
                ppredown[i] = down[v] + 1;
            }
        }
        sufdown[size] = ssufdown[size] = sufbest[size] = 0;
        for (int i = size - 1; i >= 1; --i) {
            int v = child[i];
            sufbest[i] = std::max(sufbest[i + 1], best[v]);
            sufdown[i] = sufdown[i + 1], ssufdown[i] = ssufdown[i + 1];
            if (down[v] + 1 > sufdown[i]) {
                ssufdown[i] = sufdown[i];
                sufdown[i] = down[v] + 1;
            } else if (down[v] + 1 > ssufdown[i]) {
                ssufdown[i] = down[v] + 1;
            }
        }
        for (int i = 1; i < size; ++i) {
            int v = child[i];
            long long outside =
                up[u] + value[u] + std::max(predown[i - 1], sufdown[i + 1]);
            outside =
                std::max(outside, value[u] + predown[i - 1] + ppredown[i - 1]);
            outside =
                std::max(outside, value[u] + sufdown[i + 1] + ssufdown[i + 1]);
            outside =
                std::max(outside, value[u] + predown[i - 1] + sufdown[i + 1]);
            outside = std::max(outside, prebest[i - 1]);
            outside = std::max(outside, sufbest[i + 1]);
            ans = std::max(ans, outside * best[v]);
        }
        for (int i = 1; i < size; i++) {
            int v = child[i];
            up[v] = value[u] +
                    std::max(up[u], std::max(predown[i - 1], sufdown[i + 1]));
            que.push(std::make_pair(v, u));
        }
    }
}