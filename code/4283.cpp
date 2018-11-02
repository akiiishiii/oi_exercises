// 4283.cpp
#include <iostream>

int const SIZE = 200005;
int head[SIZE], ver[SIZE << 1], Next[SIZE << 1];
int tot, n, s[SIZE], maxs[SIZE], minx = 0x3f3f3f3f, ans = 0, ans2 = 0;
bool v[SIZE] = {false};

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void dfs(int x, int prt);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        std::cin >> a >> b;
        ::add(++a, ++b), ::add(b, a);
    }
    ::dfs(1, 0);
    std::cout << minx << ' ' << (ans2 ? 2 : 1) << '\n'
              << ans - 1;
    if (ans2)
        std::cout << ' ' << ans2 << '\n';
    return 0;
}

void dfs(int x, int prt) {
    s[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt)
            continue;
        dfs(y, x);
        s[x] += s[y];
        maxs[x] = std::max(maxs[x], s[y]);
    }
    maxs[x] = std::max(maxs[x], n - s[x]);
    if (maxs[x] == minx)
        ans2 = x;
    else if (maxs[x] < minx)
        minx = maxs[x],
        ans = x, ans2 = 0;
}