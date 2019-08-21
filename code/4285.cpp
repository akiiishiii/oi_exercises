// 4285.cpp
#include <iostream>

int const Maxn = 200005, Mod = 10007;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1], v[Maxn];
int n, ans, maxans, tot;

inline void add(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        std::cin >> x >> y;
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++)
        std::cin >> v[i];
    for (int x = 1; x <= n; x++) {
        int sum = 0, maxx = 0, m = 0;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if (v[y] > maxx) {
                m = maxx;
                maxx = v[y];
            } else if (v[y] > m)
                m = v[y];
            ans = (ans + sum * v[y]) % Mod;
            sum = (sum + v[y]) % Mod;
        }
        maxans = std::max(maxans, maxx * m);
    }
    std::cout << maxans << ' ' << (ans * 2) % Mod << '\n';
    return 0;
}

inline void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}