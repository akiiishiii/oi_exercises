// dishes.cpp
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("dishes.in");
std::ofstream out("dishes.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 100005;
int cnt, tot, n, m, indeg[Maxn], ans[Maxn];
int head[Maxn], Next[Maxn], ver[Maxn];
std::priority_queue<int> q;

inline void add(int u, int v);
void topsort();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int T;
    in >> T;
    while (T--) {
        in >> n >> m;
        memset(head, 0, sizeof(head));
        memset(indeg, 0, sizeof(indeg));
        while (q.size())
            q.pop();
        tot = cnt = 0;
        for (int i = 1, x, y; i <= m; i++) {
            in >> x >> y;
            add(y, x);
            indeg[x]++;
        }
        topsort();
        if (cnt >= n) {
            for (int i = cnt; i >= 1; i--)
                out << ans[i] << ' ';
            out << '\n';
        } else
            out << "Impossible!\n";
    }
    return 0;
}

inline void add(int u, int v) {
    ver[++tot] = v, Next[tot] = head[u], head[u] = tot;
}

void topsort() {
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q.push(i);
    while (q.size()) {
        int x = q.top();
        q.pop();
        ans[++cnt] = x;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            indeg[y]--;
            if (!indeg[y])
                q.push(y);
        }
    }
}