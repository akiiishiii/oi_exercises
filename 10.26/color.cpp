// color.cpp
#include <iostream>
#include <fstream>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("color.in");
std::ofstream out("color.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxm = 10005;
int head[Maxm], ver[Maxm << 1], Next[Maxm << 1];
int deg[Maxm] = {0}, f[Maxm][2];
int n, m, tot, ans = 0x3f3f3f3f;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x, int prt);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> m >> n;
    for (int i = 1, x; i <= n; i++) {
        in >> x;
        f[i][x]++;
    }
    for (int i = 1, a, b; i < m; i++) {
        in >> a >> b;
        add(a, b), add(b, a);
    }
    for (int i = n + 1; i <= m; i++) {
        dfs(i, 0);
        int lca = 0, tmp = 1, c = int(f[lca][1] > f[lca][0]);
        for (int j = head[i]; j; j = Next[i]) {
            int y = ver[j];
            if (y == 0)
                continue;
            if (f[i][0] != f[y][0] && f[i][1] != f[y][1])
                lca = i;
        }
        for (int j = head[lca]; j; j = Next[j])
            if (f[ver[j]][1 - c])
                tmp++;
        ans = std::min(ans, tmp);
    }
    out << ans << '\n';
    return 0;
}

void dfs(int x, int prt) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt)
            continue;
        dfs(y, x);
        f[x][1]+=f[y][1];
		f[x][0]+=f[y][0];
    }
}