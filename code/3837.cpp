// 3837.cpp
#include <cstring>
#include <iostream>
#include <iomanip>
#include <queue>

double const eps = 1e-9;
int n, m;
int head[1005], ver[50005], Next[50005], tot = 0;
int v[1005], inqueue[1005], vis[1005];
double d[1005], edge[50005];

struct edges {
    int x, y, z;
} e[5005];

inline void add(int x, int y, double z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void rebuild(double k);
bool spfa();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    double l = 0.0, r = 0.0, mid;
    for (int i = 1; i <= n; i++)
        std::cin >> v[i], r += double(v[i]);
    for (int i = 1; i <= m; i++)
        std::cin >> e[i].x >> e[i].y >> e[i].z;
    while (r - l > eps) {
        mid = (l + r) / 2.0;
        rebuild(mid);
        if (spfa())
            r = mid;
        else
            l = mid;
    }
    std::cout << std::fixed << std::setprecision(2) << mid << '\n';
    return 0;
}

void rebuild(double k) {
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(inqueue, 0, sizeof(inqueue));
    for (int i = 1; i <= n; i++)
        d[i] = 0x3f3f3f3f;
    tot = 0;
    for (int i = 1; i <= m; i++)
        add(e[i].x, e[i].y, double(e[i].z) * k - double(v[e[i].y]));
}

bool spfa() {
    std::queue<int> q;
    d[1] = 0;
    q.push(1);
    inqueue[1] = 1;
    vis[1]++;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        inqueue[x] = 0;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if (d[y] > d[x] + edge[i]) {
                d[y] = d[x] + edge[i];
                if (!inqueue[y]) {
                    q.push(y);
                    inqueue[y] = 1;
                    vis[y]++;
                    if (vis[y] >= n)
                        return false;
                }
            }
        }
    }
    return true;
}