// path.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <utility>

//#define debug

#ifndef debug

std::ifstream in("path.in");
std::ofstream out("path.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const N = 10010, M = 100010;
int head[N], ver[M], edge[M], Next[M], d[N];
bool v[N];
int n, m, tot;
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
    }
    if (m <= 0 || n <= 0) {
        out << "-1\n";
        return 0;
    }
    spfa(1);
    if (d[n] == 0xcfcfcfcf) {
        out << "-1";
    } else
        out << d[n];
    out << '\n';
    return 0;
}

void spfa(int mx) {
    memset(d, 0xcf, sizeof(d));
    memset(v, false, sizeof(v));
    d[mx] = 0; v[mx] = true;
    q.push(mx);
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] < d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y]) q.push(y), v[y] = true;
            }
        }
    }
}
