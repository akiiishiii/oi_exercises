// 1002.cpp
#include <algorithm>
#include <iostream>
#include <utility>

int n, d[500005], len;
std::pair<int, int> a[500005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].first >> a[i].second;
    std::sort(a + 1, a + 1 + n);
    d[++len] = a[1].second;
    for (int i = 2; i <= n; i++) {
        int l = std::upper_bound(d + 1, d + len + 1, a[i].second) - d;
        d[l] = a[i].second;
        if (l > len)
            len++;
    }
    std::cout << len << '\n';
    return 0;
}