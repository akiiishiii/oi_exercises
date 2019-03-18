#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

#define __int128 long long

int const Maxn = 400010;
long long n, tot;
long long head[Maxn], ver[Maxn << 1], Next[Maxn << 1], edge[Maxn << 1];
__int128 best[Maxn], down[Maxn];
__int128 prebest[Maxn], sufbest[Maxn], predown[Maxn], ppredown[Maxn];
__int128 sufdown[Maxn], ssufdown[Maxn], up[Maxn];
__int128 ans = -1;

inline void add(int x, int y, int z) { ver[++tot] = y; edge[tot] = z; Next[tot] = head[x]; head[x] = tot; }
void dfs(long long x, long long p);
void solve();
inline void write(__int128 x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (long long i = 1, u, v, w; i < n; i++) {
        std::cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    dfs(1, 0);
    solve();
    for (long long i = 1; i <= tot; i++)
        edge[i] = -edge[i];
    memset(best, 0, sizeof(best));
    memset(down, 0, sizeof(down));
    memset(up, 0, sizeof(up));
    dfs(1, 0);
    solve();
    write(ans);
    std::cout.put('\n');
    return 0;
}

void dfs(long long x, long long p) {
    __int128 maxx = 0, smax = 0;
    for (long long i = head[x]; i; i = Next[i]) {
        long long y = ver[i], z = edge[i];
        if (y == p)
            continue;
        dfs(y, x);
        long long t = down[y] + z;
        if (t > maxx) {
            smax = maxx;
            maxx = t;
        } else if (t > smax) {
            smax = t;
        }
        best[x] = std::max(best[x], best[y]);
    }
    down[x] = maxx;
    best[x] = std::max(best[x], maxx + smax);
    return;
}

void solve() {
    std::queue<std::pair<long long, long long>> q;
    q.push(std::make_pair(1, 0));
    while (q.size()) {
        std::pair<long long, long long> cur = q.front();
        long long x = cur.first, p = cur.second;
        q.pop();
        std::vector<std::pair<long long, long long>> child;
        child.push_back(std::make_pair(0, 0));
        for (long long i = head[x]; i; i = Next[i]) {
            long long y = ver[i], z = edge[i];
            if (y != p)
                child.push_back(std::make_pair(y, z));
        }
        long long size = child.size();
        prebest[0] = predown[0] = ppredown[0] = 0;
        for (long long i = 1; i < size; i++) {
            long long y = child[i].first, z = child[i].second;
            prebest[i] = std::max(prebest[i - 1], best[y]);
            predown[i] = predown[i - 1], ppredown[i] = ppredown[i - 1];
            if (down[y] + z > predown[i]) {
                ppredown[i] = predown[i];
                predown[i] = down[y] + z;
            } else if (down[y] + z > ppredown[i]) {
                ppredown[i] = down[y] + z;
            }
        }
        sufbest[size] = sufdown[size] = ssufdown[size] = 0;
        for (long long i = size - 1; i >= 1; i--) {
            long long y = child[i].first, z = child[i].second;
            sufbest[i] = std::max(sufbest[i + 1], best[y]);
            sufdown[i] = sufdown[i + 1], ssufdown[i] = ssufdown[i + 1];
            if (down[y] + z > sufdown[i]) {
                ssufdown[i] = sufdown[i];
                sufdown[i] = down[y] + z;
            } else if (down[y] + z > ssufdown[i]) {
                ssufdown[i] = down[y] + z;
            }
        }
        for (long long i = 1; i < size; i++) {
            long long y = child[i].first;
            __int128 outside = up[x] + std::max(predown[i - 1], sufdown[i + 1]);
            outside = std::max(outside, predown[i - 1] + ppredown[i - 1]);
            outside = std::max(outside, sufdown[i + 1] + ssufdown[i + 1]);
            outside = std::max(outside, predown[i - 1] + sufdown[i + 1]);
            outside = std::max(outside, std::max(prebest[i - 1], sufbest[i + 1]));
            if (outside * best[y] > ans)
                ans = outside * best[y];
        }
        for (long long i = 1; i < size; i++) {
            long long y = child[i].first, z = child[i].second;
            up[y] = z + std::max(up[x], std::max(predown[i - 1], sufdown[i + 1]));
            q.push(std::make_pair(y, x));
        }
    }
    return;
}

inline void write(__int128 x) {
    if (x >= 10)
        write(x / 10);
    std::cout.put((x % 10) + 48);
    return;
}