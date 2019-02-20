// 5233.cpp
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

int const Maxn = 10020;
std::queue<std::pair<int, int>> q;
int ver[Maxn << 1], edge[Maxn << 1], Next[Maxn << 1];
int m, n, p, status[Maxn], head[Maxn], tot;
int cnt, d[Maxn][1 << 6];
bool inqueue[Maxn][1 << 6];

inline void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void spfa();
void steiner_tree();
int findmin();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> n >> m >> p) {
        memset(head, 0, sizeof(head));
        memset(inqueue, 0, sizeof(inqueue));
        tot = 0, cnt = 1 << (n + 1);
        for (int i = 0; i <= n + m; i++)
            for (int j = 0; j <= cnt; j++)
                d[i][j] = 0x3f3f3f3f;
        for (int i = 0; i <= n; i++) {
            status[i] = 1 << i;
            d[i][status[i]] = 0;
        }
        for (int i = 1, x; i <= n + m; i++)
            std::cin >> x, add(0, i, x), add(i, 0, x);
        for (int i = 1, x, y, z; i <= p; i++)
            std::cin >> x >> y >> z, add(x, y, z), add(y, x, z);
        steiner_tree();
        std::cout << findmin() << '\n';
    }
    return 0;
}

void spfa() {
    while (q.size()) {
        std::pair<int, int> x = q.front();
        q.pop();
        inqueue[x.first][x.second] = false;
        for (int i = head[x.first]; i; i = Next[i]) {
            int y = ver[i], now = x.second | status[y];
            if (d[x.first][x.second] + edge[i] < d[y][now]) {
                d[y][now] = d[x.first][x.second] + edge[i];
                if (now == x.second && !inqueue[y][now]) {
                    q.push(std::make_pair(y, now));
                    inqueue[y][now] = true;
                }
            }
        }
    }
}

void steiner_tree() {
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j <= n + m; j++) {
            if ((!(i & status[j])) && j <= n)
                continue;
            for (int k = i; k; k = (k - 1) & i) {
                if (k < i / 2)
                    break;
                d[j][i] = std::min(d[j][i], d[j][k | status[j]] +
                                                d[j][(i - k) | status[j]]);
            }
            if (d[j][i] < 0x3f3f3f3f)
                q.push(std::make_pair(j, i)), inqueue[j][i] = true;
        }
        spfa();
    }
}

int findmin() {
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= n + m; i++)
        ans = std::min(ans, d[i][cnt - 1]);
    return ans;
}