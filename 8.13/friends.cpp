// friends.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("friends.in");
std::ofstream out("friends.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 100005;
int head[Maxn], ver[Maxn << 1], edge[Maxn << 1], Next[Maxn << 1];
int n, tot;

inline void add(int x, int y, int z);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    in >> n;
    for (int i = 1, u, v, w; i <= n; i++) {
        in >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    return 0;
}

inline void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}