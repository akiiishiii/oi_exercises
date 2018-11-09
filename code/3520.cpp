// 3520.cpp
#include <iomanip>
#include <iostream>
#include <queue>
#include <cstring>

int const Maxn = 205, Maxm = 20005;
int head[Maxn], ver[Maxm << 1], edge[Maxm << 1], Next[Maxm << 1];
int n, m, s, tot;
int d[Maxn], prt[Maxn], val[Maxn], son[Maxn];
double p[Maxn][Maxn], f[Maxn][Maxn], g[Maxn][Maxn];
std::queue<int> q;

inline void add(int x, int y, int z);
void dfs(int x, int prt);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for (int i = 1, a, b, c; i <= m; i++) {
        std::cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    std::cin >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= s; j++)
            std::cin >> p[i][j];

    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    q.push(1);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if (d[y] > d[x] + edge[i]) {
                d[y] = d[x] + edge[i];
                prt[y] = x;
                val[y] = edge[i];
                q.push(y);
            }
        }
    }

    memset(head, 0, sizeof(head));
	tot = 0;
	for(int i = 2; i <= n; i++) {
		add(i, prt[i], val[i]);
		add(prt[i], i, val[i]);
		son[prt[i]]++;
	}

    dfs(1, 0);

    std::cout << std::fixed << std::setprecision(4) << f[1][s] << '\n';

    return 0;
}

inline void add(int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int prt) {
    if (!head[x]) {
        for (int i = 1; i <= s; i++)
            f[x][i] = p[x][i];
        return;
    }
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt)
            continue;
        dfs(y, x);
        for (int j = s; j >= 0; j--) {
            for (int k = 0; k <= j; k++) {
                g[x][j] = std::max(g[x][j], g[x][j - k] + f[y][k] / son[x]);
            }
        }
    }
    for (int i = 0; i <= s; i++) {
        for (int j = 0; j <= i; j++) {
            f[x][i] = std::max(f[x][i], g[x][i - j] * (1 - p[x][j]) + p[x][j]);
        }
    }
}