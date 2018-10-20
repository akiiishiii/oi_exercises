// 1012.cpp
#include <iostream>

int const Maxn = 301, Maxm = 201;
int head[Maxn], ver[Maxm], Next[Maxm];
int tot;
int indeg[Maxn];

inline void add(int u, int v) { ver[++tot] = v, Next[tot] = head[u], head[u] = tot; }

int main(int argc, char const *argv[]) {

    return 0;
}