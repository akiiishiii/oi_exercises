// 1379.cpp
#include <iostream>
#include <algorithm>

long long a[55], s[10000005];
long long ans, n, w, tot;

void dfs1(long long x, long long t);
void dfs2(long long x, long long t);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> w >> n;
    for(int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    dfs1((n + 1) >> 1, 0);
    std::sort(s + 1, s + tot + 1);
    dfs2(1, 0);
    std::cout << ans << '\n';
    return 0;
}

void dfs1(long long x, long long t) {
    if(x > n) {
        s[++tot] = t;
        return;
    }
    if(a[x] + t <= w)
        dfs1(x + 1, a[x] + t);
    dfs1(x + 1, t);
}

void dfs2(long long x, long long t) {
    if(x >= (n + 1) >> 1) {
        long long l = std::lower_bound(s + 1, s + tot + 1, w - t) - (s + 1);
        ans = std::max(ans, t + s[l]);
        return;
    }
    if(a[x] + t <= w)
        dfs2(x + 1, a[x] + t);
    dfs2(x + 1, t);
}
