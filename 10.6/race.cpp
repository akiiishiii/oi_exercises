// race.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>

//#define debug

#ifndef debug

std::ifstream in("race.in");
std::ofstream out("race.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const N = 200005;
int head[N], Next[N << 1], ver[N << 1], edge[N << 1];
int n, m, tot, ans;
int f[N];
std::deque<int> q1, q2;

inline void add(int x, int y, int z) { ver[++tot] = y; edge[tot] = z; Next[tot] = head[x]; head[x] = tot; }
void dfs(int u, int past, int path, int &rem);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int x = 0, y = 0, len = 1;
    in >> n >> m;
    for (int i = 2, mx, my; i <= n; i++) {
        in >> mx >> my;
        add(i, mx, my);
        add(mx, i, my);
    }
    dfs(1, 0, 0, x);
    dfs(x, 0, 0, y);
    dfs(y, 0, 0, x);
    for (int i = 1; i <= n; i++) {
        while (q1.size() && f[q1.back()] <= f[i])
            q1.pop_back();
        q1.push_back(i);
        while (q2.size() && f[q2.back()] <= f[i])
            q2.pop_back();
        q2.push_back(i);
        while (f[q1.front()] - f[q2.front()] > m) {
            if (len == q1.front())
                q1.pop_front();
            if (len == q2.front())
                q2.pop_front();
            len++;
        }
        ans = std::max(ans, i - len + 1);
    }
    out << ans << '\n';
    return 0;
}

void dfs(int u, int past, int path, int &rem) {
    if (path > f[rem])
        rem = u;
    if (path > f[u])
        f[u] = path;
    for (int i = head[u]; i; i = Next[i])
        if (ver[i] != past)
            dfs(ver[i], u, path + edge[i], rem);
}