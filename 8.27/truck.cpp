// truck.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("truck.in");
std::ofstream out("truck.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const N = 10010, M = 50010;
int head[N << 1], ver[M << 1], edge[M << 1], Next[M << 1], d[N];
bool v[N];
int n, m, tot, last = 0;
std::queue<int> q;

void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void spfa(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    for (int i = 1, x, y, z; i <= m; i++) {
        in >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    int q;
    in >> q;
    for (int i = 1, x, y; i <= q; i++) {
        in >> x >> y;
        if (x != last)
            spfa(x);
        last = x;
        if (d[y] == 0x3f3f3f3f)
            out << "-1\n";
        else
            out << d[y] << '\n';
    }
    return 0;
}

void spfa(int mx) {
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    v[mx] = true;
    q.push(mx);
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i], minn = std::min(d[x], z);
            if (d[y] < minn || d[y] == 0x3f3f3f3f) {
                d[y] = minn;
                if (!v[y]) q.push(y), v[y] = true;
            }
        }
    }
}