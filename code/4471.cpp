// 4471.cpp
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

long long n, k, x, ans1 = 0, ans2 = 0;
std::pair<long long, long long> sum;
std::priority_queue<std::pair<long long, long long>,
                    std::vector<std::pair<long long, long long>>,
                    std::greater<std::pair<long long, long long>>>
    q;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> x, q.push(std::make_pair(x, 0ll));
    while (k > 2 && (n - 1) % (k - 1))
        q.push(std::make_pair(0ll, 0ll)), n++;
    while (q.size() > 1) {
        sum = std::make_pair(0ll, 0ll);
        for (int i = 1; i <= k; i++) {
            sum = std::make_pair(sum.first + q.top().first,
                                 std::max(sum.second, q.top().second + 1ll));
            q.pop();
        }
        q.push(sum), ans1 += sum.first, ans2 = std::max(ans2, sum.second);
    }
    std::cout << ans1 << '\n' << ans2 << '\n';
    return 0;
}