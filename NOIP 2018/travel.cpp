// travel.cpp
#include <iostream>
#include <fstream>
#include <cstring>

//#define debug

#ifndef debug

std::ifstream in("travel.in");
std::ofstream out("travel.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 5005, Maxm = 5005;
//int head[Maxn], ver[Maxm << 1], edge[Maxm << 1], Next[Maxm << 1], tot;
int mat[Maxn][Maxn];
int m, n, l, r;
int prt[Maxn], ring[Maxn] = {0};
bool find = false;

//inline void add(int a, int b) { ver[++tot] = b, Next[tot] = head[a], head[a] = tot; }
inline int abs(int x) {
    return ((x < 0) ? (-x) : x);
}
void dfs(int x, int p);
void find_ring(int x, int p, int d);
int search(int x) {
    return ((prt[x] == x) ? x : (prt[x] = search(prt[x])));
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    memset(mat, 0, sizeof(mat));
    in >> n >> m;
    if (n == m) {
        for (int i = 0; i <= n; i++)
            prt[i] = i;
        for (int i = 1, u, v; i <= m; i++) {
            in >> u >> v;
            int pu = search(u), pv = search(v);
            if (pu == pv) {
                l = u, r = v;
            } else {
                prt[pu] = pv;
                mat[u][v] = mat[v][u] = 1;
            }
        }
        find_ring(l, 0, r);
        for (int i = 2; i <= ring[0]; i++)
            if (::abs(ring[i] - ring[i - 1]) > ::abs(l - r))
                mat[l][r] = mat[r][l] = 1, mat[ring[i]][ring[i - 1]] = mat[ring[i - 1]][ring[i]] = 0, l = ring[i - 1], r = ring[i];
        dfs(1, 0);
    } else {
        for (int i = 1, u, v; i <= m; i++) {
            in >> u >> v;
            //add(u, v), add(v, u);
            mat[u][v] = mat[v][u] = 1;
        }
        dfs(1, 0);
    }
    return 0;
}

void dfs(int x, int p) {
    out << x << ' ';
    //for (int i = head[x]; i; i = Next[i]) {
    for (int y = 1; y <= n; y++) {
        //int y = ver[i];
        if (y == p || !mat[x][y])
            continue;
        dfs(y, x);
    }
}

void find_ring(int x, int p, int d) {
    if (x == d) {
        find = true;
        ring[++ring[0]] = x;
        return;
    }
    for (int y = 1; y <= n; y++) {
        //int y = ver[i];
        if (y == p || !mat[x][y])
            continue;
        find_ring(y, x, d);
        if (find) {
            ring[++ring[0]] = x;
            return;
        }
    }
}
