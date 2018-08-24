// 1581.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

const int N = 10010, M = 100010;
int head[N], ver[M], edge[M], Next[M], d[N];
int n, m, tot;
std::queue<int> q;
bool v[N];

void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void spfa(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int s, t;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        add(x, y, z);
    }
    std::cin >> s >> t;
    spfa(s);
    if (d[t] == 0x3f3f3f3f)
        std::cout << "No Solution!\n";
    else
        std::cout << d[t] << '\n';
    return 0;
}

void spfa(int mx) {
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    d[mx] = 0; v[mx] = true;
    q.push(mx);
    while (q.size()) {
        int x = q.front(); q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y]) q.push(y), v[y] = true;
            }
        }
    }
}