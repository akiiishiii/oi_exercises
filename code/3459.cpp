// 3459.cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>

int n, a[100001], f[100001], maxx = 0, sum = 0;
std::pair<int, int> s[100001];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i].second >> s[i].first;
        if (!s[i].second)
            s[i].second = -1;
    }
    std::sort(s + 1, s + n + 1);
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; i++) {
        maxx += s[i].second;
        if (f[maxx] == -1)
            f[maxx] = i;
        else
            sum = std::max(sum, s[i].first - s[f[maxx] + 1].first);
    }
    std::cout << sum << '\n';
    return 0;
}