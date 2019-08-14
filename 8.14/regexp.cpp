// regexp.cpp
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("regexp.in");
std::ofstream out("regexp.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 200005, Maxm = 1000005;
int head[Maxn], ver[Maxm], edge[Maxm], Next[Maxm];
int headed[Maxn], vered[Maxm], edged[Maxm], Nexted[Maxm];
int sta[Maxn], c[Maxn], dfn[Maxn], low[Maxn], d[Maxn];
bool ins[Maxn], v[Maxn];
int n, m, tot, toted, cnt, sign, scc;
std::queue<int> q;

inline void add(int x, int y, int z);
inline void added(int x, int y, int z);
void tarjan(int x);
void spfa(int s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++)
        in >> u >> v >> w, add(u, v, w);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int x = 1; x <= n; x++)
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (c[x] == c[y])
                continue;
            added(c[x], c[y], z);
        }
    spfa(1);
    out << d[c[n]] << '\n';
    return 0;
}

inline void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

inline void added(int x, int y, int z) {
    vered[++toted] = y, edged[toted] = z, Nexted[toted] = headed[x],
    headed[x] = toted;
}

void tarjan(int x) {
    low[x] = dfn[x] = ++sign;
    sta[++cnt] = x;
    ins[x] = true;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (!edge[i])
            continue;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = std::min(low[x], low[y]);
        } else if (ins[y])
            low[x] = std::min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        scc++;
        int t;
        do {
            t = sta[cnt--];
            c[t] = scc;
            ins[t] = false;
        } while (t != x);
    }
}

void spfa(int s) {
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    d[c[s]] = 0;
    v[c[s]] = true;
    q.push(c[s]);
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = 0;
        for (int i = headed[x]; i; i = Nexted[i]) {
            int y = vered[i], z = edged[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y])
                    q.push(y), v[y] = 1;
            }
        }
    }
}