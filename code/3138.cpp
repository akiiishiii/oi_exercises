// 3138.cpp
#include <iostream>
#include <cstring>
#include <queue>

int const Maxn = 1010, Maxm = 10010;
int head[Maxn], ver[Maxm], edge[Maxm], Next[Maxm], d[Maxn][Maxn];
int n, m, tot;
std::queue<int> q;
bool v[Maxn];

void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void spfa(int s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int minn = 0x3f3f3f3f;
    std::cin >> n >> m;
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        add(x, y, z);
    }
    for (int i = 1; i <= n; i++)
        spfa(i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                minn = std::min(minn, d[i][j] + d[j][i]);
    std::cout << minn << '\n';
    return 0;
}

void spfa(int s) {
    memset(v, false, sizeof(v));
    for (int t = 1; t <= n; ++t)
        d[s][t] = 0x3f3f3f3f;
    d[s][s] = 0;
    q.push(s);
    v[s] = true;
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
        	int y = ver[i], z = edge[i];
            if (d[s][y] > z + d[s][x]) {
                d[s][y] = z + d[s][x];
                if (!v[y]) {
                    v[y] = true;
                    q.push(y);
                }
            }
        }
    }
}
