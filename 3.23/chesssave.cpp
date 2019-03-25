// chess.cpp HASH + 记忆化搜索
#include <fstream>
#include <iostream>
#include <map>

#define debug

#ifndef debug

std::ifstream in("chess.in");
std::ofstream out("chess.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 15, Base = 11;
int n, m;
int l[Maxn], a[Maxn][Maxn], b[Maxn][Maxn];
std::map<long long, int> mp;

int dfs(long long x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    l[0] = m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            in >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            in >> b[i][j];
    long long tot = 0;
    for (int i = 1; i <= n; i++)
        tot = tot * Base + m;
    mp[tot] = 0;
    dfs(0);
    out << mp[0] << '\n';
    return 0;
}

int dfs(long long x) {
    if (mp.find(x) != mp.end())
        return mp[x];
    for (int i = n; i; i--)
        l[i] = x % Base, x /= Base;
    int opt = 0, ret;
    for (int i = 1; i <= n; i++)
        opt += l[i];
    opt &= 1;
    ret = opt ? 1e9 : -1e9;
    for (int i = 1, hash; i <= n; i++)
        if (l[i - 1] > l[i]) {
            l[i]++;
            hash = 0;
            for (int i = 1; i <= n; i++)
                hash = hash * Base + l[i];
            if (opt)
                ret = std::min(ret, dfs(hash) - b[i][l[i]]);
            else
                ret = std::max(ret, dfs(hash) + a[i][l[i]]);
            l[i]--;
        }
    return mp[x] = ret;
}