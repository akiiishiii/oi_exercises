// 2454.cpp
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>

int n, m, s, t, tot = 1, tot1 = 0;
int dis[125000], vst[125000], head[125000], head1[125000], d[125000], gap[125000];

struct edges {
    int p, q, t, c;
} g[125000];

struct edge {
    int next, to, flow;
} a[250000];

struct edge1 {
    int next, to, value, c;
} b[250000];

void add1(int x, int y, int z, int c);
void add(int x, int y, int z);
int dfs(int x, int maxf, int to);
int dijkstra();
void add();
int sap(int st, int to);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    s = 1, t = n;
    for (int i = 1; i <= m; i++) {
        std::cin >> g[i].p >> g[i].q >> g[i].t >> g[i].c;
        add1(g[i].p, g[i].q, g[i].t, g[i].c), add1(g[i].q, g[i].p, g[i].t, g[i].c);
    }
    std::cout << dijkstra() << '\n';
    add();
    std::cout << sap(s, t) << '\n';
    return 0;
}

void add1(int x, int y, int z, int c) {
    b[++tot1].next = head1[x];
    b[tot1].to = y;
    b[tot1].value = z;
    b[tot1].c = c;
    head1[x] = tot1;
}

void add(int x, int y, int z) {
    a[++tot].next = head[x];
    a[tot].to = y;
    a[tot].flow = z;
    head[x] = tot;
    a[++tot].next = head[y];
    a[tot].to = x;
    a[tot].flow = 0;
    head[y] = tot;
}

int dfs(int x, int maxf, int to) {
    if (x == to)
        return maxf;
    int dlt, ans = 0;
    for (int i = head[x]; i; i = a[i].next) {
        int t = a[i].to;
        if (a[i].flow && d[x] == d[t] + 1) {
            dlt = dfs(t, std::min(maxf, a[i].flow), to);
            maxf -= dlt;
            ans += dlt;
            a[i].flow -= dlt;
            a[i ^ 1].flow += dlt;
            if (d[s] == n || !maxf)
                return ans;
        }
    }
    gap[d[x]]--;
    if (!gap[d[x]])
        d[s] = n;
    gap[++d[x]]++;
    return ans;
}

int dijkstra() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for (int i = head1[1]; i; i = b[i].next) {
        int t = b[i].to;
        dis[t] = b[i].value;
        q.push(std::make_pair(dis[t], t));
    }
    while (!q.empty()) {
        std::pair<int, int> u = q.top();
        q.pop();
        int x = u.second;
        vst[x] = 1;
        for (int i = head1[x]; i; i = b[i].next) {
            int t = b[i].to;
            if (!vst[t] && dis[t] > dis[x] + b[i].value) {
                dis[t] = dis[x] + b[i].value;
                q.push(std::make_pair(dis[t], t));
            }
        }
    }
    return dis[n];
}

void add() {
    for (int i = 1; i <= n; i++) {
        for (int j = head1[i]; j; j = b[j].next) {
            int t = b[j].to;
            if (dis[t] == dis[i] + b[j].value)
                add(i, t, b[j].c);
        }
    }
}

int sap(int st, int to) {
    gap[0] = n;
    int ans = 0;
    while (d[st] < n)
        ans += dfs(st, 0x7fffffff / 2, to);
    return ans;
}