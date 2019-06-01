// 3479.cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

int n, m, ans;
std::priority_queue<int> q;
std::pair<int, int> cow[3005], scr[3005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> cow[i].first >> cow[i].second;
    for (int i = 1; i <= m; i++)
        std::cin >> scr[i].first >> scr[i].second;
    std::sort(cow + 1, cow + n + 1);
    std::sort(scr + 1, scr + m + 1);
    int top = 1;
    for (int i = 1; i <= m; i++) {
        while (top <= n && cow[top].first <= scr[i].first)
            q.push(-cow[top++].second);
        while (!q.empty() && scr[i].second) {
            int t = q.top();
            if ((-t) >= scr[i].first)
                ans++, scr[i].second--;
            q.pop();
        }
    }
    std::cout << ans << '\n';
    return 0;
}