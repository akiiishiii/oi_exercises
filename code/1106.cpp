// 1106.cpp
#include <algorithm>
#include <iostream>
#include <utility>

int const Maxn = 100005;
int const Mod = 9901;
int m, n, p[Maxn], a[Maxn];
std::pair<int, int> e[Maxn];

int search(int x);
inline int lowbit(int x) { return x & -x; }
void add(int x, int v);
int ask(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int ans = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> e[i].first;
        e[i].second = i;
    }
    std::sort(e + 1, e + 1 + n);
    for (int i = 1; i <= n; i++)
        p[e[i].second] = i;
    e[0].first = 0;
    for (int i = 1; i <= n; i++) {
        int r = search(e[p[i]].first + m), l = search(e[p[i]].first - m - 1);
        int tmp = ask(r) - ask(l) + 1;
        ans = (ans + (tmp)) % Mod;
        add(p[i], tmp);
    }
    ans = (ans - n) % Mod;
    if (ans < 0)
        ans += Mod;
    std::cout << ans << '\n';
    return 0;
}

int search(int x) {
    int l = 0, r = n, mid = (l + r + 1) >> 1;
    while (l < r) {
        if (e[mid].first <= x)
            l = mid;
        else
            r = mid - 1;
        mid = (l + r + 1) >> 1;
    }
    return mid;
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        a[i] = (a[i] + v) % Mod;
}

int ask(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ret = (ret + a[i]) % Mod;
    return ret;
}