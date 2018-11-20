// 1227.cpp
#include <cstring>
#include <iostream>

int const Maxn = 100005;
int c[Maxn], n;

inline int lowbit(int const x) { return x & (-x); }
void add(int x, int d);
int sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while ((std::cin >> n) && n) {
        memset(c, 0, sizeof(c));
        for (int i = 1, l, r; i <= n; i++) {
            std::cin >> l >> r;
            add(l, 1);
            add(r + 1, -1);
        }
        for (int i = 1; i <= n; i++)
            std::cout << sum(i) << ' ';
        std::cout << '\n';
    }
    return 0;
}

void add(int x, int d) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += d;
}

int sum(int x) {
    int i, ret = 0;
    for (i = x; i > 0; i -= lowbit(i))
        ret += c[i];
    return ret;
}
