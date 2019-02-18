// plan.cpp 0/1分数规划 + 树上DP
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("plan.in");
std::ofstream out("plan.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 110, Maxm = 1000010;
double const eps = 1e-6;
double f[Maxn][Maxn], d[Maxn] = {0};
bool vis[Maxn] = {false};
int siz[Maxn] = {0}, w[Maxn], v[Maxn];
int head[Maxm], ver[Maxm], Next[Maxm], tot;
int n, m;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x);
bool chk(double x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    m = n - m;
    for (int i = 1; i <= n; i++)
        in >> w[i];
    for (int i = 1; i <= n; i++)
        in >> v[i];
    for (int i = 1, a, b; i < n; i++)
        in >> a >> b, add(a, b), add(b, a);
    double l = 0.0, r = 100000.0;
    while (r - l > eps) {
        double mid = (l + r) * 1.0 / 2.0;
        if (chk(mid))
            l = mid;
        else
            r = mid;
    }
    out << std::fixed << std::setprecision(1) << l << '\n';
    return 0;
}

void dfs(int x) {
    vis[x] = true, siz[x] = 1;
    f[x][1] = d[x], f[x][0] = 0;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (vis[y])
            continue;
        dfs(y), siz[x] += siz[y];
        for (int j = std::min(m, siz[x]); j >= 1; j--)
            for (int k = 0; k < j; k++)
                f[x][j] = std::max(f[x][j], f[x][j - k] + f[y][k]);
    }
}

bool chk(double x) {
    for (int i = 1; i <= n; i++)
        d[i] = w[i] * 1.0 - v[i] * 1.0 * x, vis[i] = false, siz[i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[i][j] = -1e7;
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (f[i][m] > -eps)
            return true;
    return false;
}