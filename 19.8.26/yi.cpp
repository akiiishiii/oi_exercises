// yi.cpp
#include <cstring>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("yi.in");
std::ofstream out("yi.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 5005;
int d, n, tot, maxx, minn, cnt, ans = 0x3f3f3f3f;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
int val[Maxn];
bool vis[Maxn];

inline void add(int x, int y);
void dfs(int x, int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> d >> n;
    for (int i = 1; i <= n; i++)
        in >> val[i];
    for (int i = 1, s, t; i < n; i++) {
        in >> s >> t;
        add(s, t), add(t, s);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof vis);
        cnt = 0;
        if (!vis[i]) {
            maxx = minn = val[i];
            dfs(i, 0);
            cnt++;
        }
        ans = std::min(cnt, ans);
    }
    out << ans + 1 << '\n';
    return 0;
}

inline void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void dfs(int x, int p) {
    vis[x] = true;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == p)
            continue;
        if (val[y] > maxx) {
            if (val[y] - minn <= d) {
                maxx = val[y];
                dfs(y, x);
            }
        } else if (val[y] < minn) {
            if (maxx - val[y] <= d) {
                minn = val[y];
                dfs(y, x);
            }
        } else
            dfs(y, x);
    }
}