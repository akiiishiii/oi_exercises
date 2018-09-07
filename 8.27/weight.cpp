// weight.cpp
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("weight.in");
std::ofstream out("weight.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 21, Max_sum = 2010;
int a[Maxn];
int n, m, num, tot, ans;
bool away[Maxn], f[Max_sum];

void dp();
void dfs(int cur, int now);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    for (int i = 0; i < n; i++)
        in >> a[i];
    dfs(0, 0);
    out << ans << '\n';
    return 0;
}

void dp() {
    memset(f, false, sizeof f);
    f[0] = true;
    num = tot = 0;
    for (int i = 0; i < n; i++) {
        if (away[i])
            continue;
        for (int j = tot; j >= 0; j--)
            if (f[j] && !f[j + a[i]])
                f[j + a[i]] = true, num++;
        tot += a[i];
    }
    ans = std::max(num, ans);
}

void dfs(int cur, int now) {
    if (now > m)
        return;
    else if (cur == n) {
        if (now == m)
            dp();
        return;
    }
    dfs(cur + 1, now);
    away[cur] = true;
    dfs(cur + 1, now + 1);
    away[cur] = false;
}