// 3148.cpp
#include <iostream>

int const Maxn = 200005;
long long n, m, s;
long long w[Maxn], v[Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        std::cin >> w[i] >> v[i];
    for (int i = 1, l, r; i <= m; i++) {
        std::cin >> l >> r;
    }
    return 0;
}