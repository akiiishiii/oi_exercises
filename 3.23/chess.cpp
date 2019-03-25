// chess.cpp
#include <iostream>
#include <map>

int const Maxn = 15, Base = 11;
std::map<long long, int> ma;
int ln[Maxn], n, m;
int a[Maxn][Maxn], b[Maxn][Maxn];

long long hash();
void unhash(long long x);
int next();
int dfs(long long x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    ln[0] = m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> b[i][j];
    long long all = 0;
    for (int i = 1; i <= n; ++i)
        all = all * Base + m;
    ma[all] = 0;
    dfs(0);
    std::cout << ma[0] << '\n';
    return 0;
}

long long hash() {
    long long ret = 0;
    for (int i = 1; i <= n; ++i)
        ret = ret * Base + ln[i];
    return ret;
}

void unhash(long long x) {
    for (int i = n; i; --i)
        ln[i] = x % Base, x /= Base;
}

int next() {
    int ret = 0;
    for (int i = 1; i <= n; ++i)
        ret += ln[i];
    return ret & 1;
}

int dfs(long long x) {
    if (ma.count(x))
        return ma[x];
    unhash(x);
    int opt = next(), ret = opt ? 1e9 : -1e9;
    for (int i = 1; i <= n; ++i)
        if (ln[i - 1] > ln[i]) {
            ln[i]++;
            long long now = hash();
            opt ? ret = std::min(ret, dfs(now) - b[i][ln[i]])
                : ret = std::max(ret, dfs(now) + a[i][ln[i]]);
            ln[i]--;
        }
    return ma[x] = ret;
}