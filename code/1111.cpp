// 1111.cpp
#include <iostream>
#include <cstring>

int const SIZE = 3005;
int head[SIZE], ver[SIZE << 1], edge[SIZE << 1], Next[SIZE << 1];
int tot, n, m;
int f[SIZE][SIZE], s[SIZE];

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
template <typename T1, typename T2>
auto max(T1 const &a, T2 const &b) -> decltype (a > b ? a : b) { return a > b ? a : b; }
void dfs(int x, int prt);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(f, 0xcf, sizeof f);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        f[i][0] = 0;
    for (int i = 1, dx, dy, dz; i <= n - m; i++) {
        std::cin >> dx;
        for (int j = 1; j <= dx; j++) {
            std::cin >> dy >> dz;
            ::add(i, dy, dz), ::add(dy, i, dz);
        }
    }
    for (int i = n - m + 1; i <= n; i++)
        std::cin >> f[i][1];
    ::dfs(1, 0);
    for (int i = m; i; i--)
        if (f[1][i] >= 0) {
            std::cout << i << '\n';
            return 0;
        }
    return 0;
}

void dfs(int x, int prt) {
    s[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt)
            continue;
        dfs(y, x);
        s[x] += s[y];
        for (int j = s[x]; j >= 1; j--)
            for (int k = 1; k <= s[y] && k <= j; k++)
                f[x][j] = ::max(f[x][j], f[y][k] + f[x][j - k] - edge[i]);
    }
}