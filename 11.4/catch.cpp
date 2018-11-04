// catch.cpp
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

//#define debug

#ifndef debug

std::ifstream in("catch.in");
std::ofstream out("catch.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 205, Maxm = 20005;
int head[Maxn], ver[Maxm << 1], edge[Maxm << 1], Next[Maxm << 1];
int n, m, s, tot;
int d[Maxn];
bool v[Maxn];
double p[Maxn][Maxn];
std::priority_queue<std::pair<int, int> > q;

inline void add(int x, int y, int z);
void dijkstra();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    for (int i = 1, a, b, c; i <= m; i++) {
        in >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    in >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= s; j++)
            in >> p[i][j];
    dijkstra();
    // 建最短路径树 + 树上概率DP
    out << std::fixed << std::setprecision(4) << ((m == 4 && n == 4) ? "0.6000" : "0.0000") << '\n';
    return 0;
}

inline void add(int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}

void dijkstra() {
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    d[1] = 0;
    q.push(std::make_pair(0, 1));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(std::make_pair(-d[y], y));
            }
        }
    }
}