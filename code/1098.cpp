// 1098.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

const int N = 50010, M = 100010;
int head[N << 1], ver[M << 1], edge[M << 1], Next[M << 1], rd[N], belong[N] = {0}, prt[N], res[6][6];
int cnt = 0, temp = 0, n, m, tot, ans = 0x3f3f3f3f;
bool v[N], vis[6] = {false};
std::priority_queue< std::pair<int, int> > q;

void add(int x, int y, int z) {	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void dijkstra(int mx);
void dfs(int mi);
void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c, d, e;
    read(n);
    read(m);
    memset(res, 0x3f, sizeof res);
    read(a);
    read(b);
    read(c);
    read(d);
    read(e);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        read(x);
        read(y);
        read(z);
        add(x, y, z);
        add(y, x, z);
    }
    dijkstra(1);
    res[0][1] = rd[a];
    res[0][2] = rd[b];
    res[0][3] = rd[c];
    res[0][4] = rd[d];
    res[0][5] = rd[e];
    dijkstra(a);
    res[1][2] = rd[b];
    res[1][3] = rd[c];
    res[1][4] = rd[d];
    res[1][5] = rd[e];
    dijkstra(b);
    res[2][1] = rd[a];
    res[2][3] = rd[c];
    res[2][4] = rd[d];
    res[2][5] = rd[e];
    dijkstra(c);
    res[3][1] = rd[a];
    res[3][2] = rd[b];
    res[3][4] = rd[d];
    res[3][5] = rd[e];
    dijkstra(d);
    res[4][1] = rd[a];
    res[4][2] = rd[b];
    res[4][3] = rd[c];
    res[4][5] = rd[e];
    dijkstra(e);
    res[5][1] = rd[a];
    res[5][2] = rd[b];
    res[5][3] = rd[c];
    res[5][4] = rd[d];
    dfs(0);
    write(ans);
    std::cout.put('\n');
    return 0;
}

void dijkstra(int mx) {
    memset(rd, 0x3f, sizeof(rd));
    memset(v, false, sizeof(v));
    rd[mx] = 0;
    prt[mx] = mx;
    q.push(std::make_pair(0, mx));
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (v[x]) continue;
        v[x] = true;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (rd[y] > rd[x] + z) {
                rd[y] = rd[x] + z;
                q.push(std::make_pair(-rd[y], y));
                prt[y] = x;
            }
        }
    }
}

void dfs(int mi) {
    if (cnt == 5) {
        ans = std::min(ans, temp);
        return;
    }
    for (int i = 1; i <= 5; i++)
        if (!vis[i] && res[mi][i] != 0x3f3f3f3f) {
            vis[i] = true;
            temp += res[mi][i];
            cnt++;
            dfs(i);
            cnt--;
            temp -= res[mi][i];
            vis[i] = false;
        }
}

void read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        std::cout.put(x / y + 48);
        x %= y;
    }
}