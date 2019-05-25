// 2590.cpp
#include <iostream>
#include <map>
#include <utility>

std::map<std::pair<int, int>, bool> v;
int c[10005], d[10005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, p, h, m;
    std::cin >> n >> p >> h >> m;
    for (int i = 1, a, b; i <= m; i++) {
        std::cin >> a >> b;
        if (a > b)
            std::swap(a, b);
        if (v[std::make_pair(a, b)])
            continue;
        d[a + 1]--, d[b]++;
        v[std::make_pair(a, b)] = true;
    }
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + d[i];
        std::cout << h + c[i] << '\n';
    }
    return 0;
}