// mobiles.cpp
#include <iostream>
#include <fstream>
#include <utility>

//#define debug

#ifndef debug

std::ifstream in("mobiles.in");
std::ofstream out("mobiles.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const N = 200005;
int n, h[N], cnt, tot, m[N][2], s[N], d[N], mx[N], mn[N];
bool flag, v[N];

void dfs(int u);
int calc(int u);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    tot = n;
    for (int i = 1; i <= n; i++)
    {
        in >> m[i][0] >> m[i][1];
        if (m[i][0] == -1)
            m[i][0] = ++tot, s[m[i][0]] = 1;
        if (m[i][1] == -1)
            m[i][1] = ++tot, s[m[i][1]] = 1;
    }
    d[1] = 1;
    dfs(1);
    if (mx[1] - mn[1] > 1 || flag)
    {
        out << "-1\n";
        return 0;
    }
    out <<  calc(1) << '\n';
    return 0;
}

void dfs(int u) {
    if (u > n) {
        mn[u] = d[u], mx[u] = d[u];
        return;
    }
    for (int i = 0; i <= 1; i++) {
        d[m[u][i]] = d[u] + 1;
        dfs(m[u][i]);
        s[u] += s[m[u][i]];
    }
    mn[u] = std::min(mn[m[u][0]], mn[m[u][1]]);
    mx[u] = std::max(mx[m[u][0]], mx[m[u][1]]);
    if (mn[u] != mx[u])
        v[u] = 1;
    if (v[m[u][0]] && v[m[u][1]])
        flag = 1;
}

int calc(int u) {
    if (u > n)
        return 0;
    return (s[m[u][1]] > s[m[u][0]]) + calc(m[u][0]) + calc(m[u][1]);
}