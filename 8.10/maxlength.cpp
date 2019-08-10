// maxlength.cpp
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>

//#define debug

#ifndef debug

std::ifstream in("maxlength.in");
std::ofstream out("maxlength.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int head[1005], ver[2005], Next[2005], edge[2005];
std::string s[31];
double dis[1010][1010], ans;
int d[1010], blo[1010];
bool v[1010];
int n, m, t, tot;

inline int id(int x, int y) { return (x - 1) * m + y; }
inline void add(int x, int y, int z);
void spfa(int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        in >> s[i];
        s[i] = ' ' + s[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= n; k++)
                for (int l = 1; l <= m; l++)
                    dis[id(i, j)][id(k, l)] =
                        sqrt((i - k) * (i - k) + (j - l) * (j - l));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '1')
                blo[id(i, j)] = 1;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 1 || ny < 1 || nx > n || ny > m)
                    continue;
                int w = s[nx][ny] - '0';
                add(id(i, j), id(nx, ny), w);
            }
        }
    for (int i = 1; i <= n * m; i++)
        spfa(i);
    out << std::fixed << std::setprecision(6) << ans << '\n';
    return 0;
}

inline void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void spfa(int k) {
    std::queue<int> q;
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[k] = blo[k];
    v[k] = true;
    q.push(k);
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = false;
        ans = std::max(ans, dis[k][x]);
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y] && d[y] <= t)
                    q.push(y), v[y] = true;
            }
        }
    }
}