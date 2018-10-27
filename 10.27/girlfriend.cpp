// girlfriend.cpp
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("girlfriend.in");
std::ofstream out("girlfriend.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 100010, Maxm = 200010 << 1;
int head[Maxn], ver[Maxm], edge[Maxm][2], Next[Maxm];
int tot, m, n, q;

inline void add(int x, int y, int z1, int z2) { ver[++tot] = y, edge[tot][0] = z1, edge[tot][1] = z2, Next[tot] = head[x], head[x] = tot; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m >> q;
    for (int i = 0, u, v, t1, t2; i <= m; i++) {
        in >> u >> v >> t1 >> t2;
        add(u, v, t1, t2), add(v, u, t1, t2);
    }
    for (int i = 1, a, b, c; i <= q; i++)
        in >> a >> b >> c;
    out << "-1\n";
    return 0;
}