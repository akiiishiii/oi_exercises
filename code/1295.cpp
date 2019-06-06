// 1295.cpp
#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int n, m, cnt, x, y;
std::vector<int> a[110], b[110];
std::multiset<std::pair<int, int>> s;
std::multiset<std::pair<int, int>>::iterator it;
long long ans;

int main(int const argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (std::cin >> n >> m) {
        for (int i = 0; i <= 100; i++)
            a[i].clear(), b[i].clear();
        for (int i = 1; i <= n; i++)
            std::cin >> x >> y, a[y].push_back(x);
        for (int i = 1; i <= m; i++)
            std::cin >> x >> y, b[y].push_back(x);
        cnt = ans = 0;
        s.clear();
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j < b[i].size(); j++)
                s.insert(std::make_pair(b[i][j], 500 * b[i][j] + (i << 1)));
            std::sort(a[i].begin(), a[i].end());
            for (int j = 0; j < a[i].size(); j++) {
                it = s.upper_bound(std::make_pair(a[i][j], 1 << 30));
                if (it == s.begin())
                    continue;
                it--;
                cnt++;
                ans += it->second;
                s.erase(it);
            }
        }
        std::cout << cnt << ' ' << ans << '\n';
    }
    return 0;
}
