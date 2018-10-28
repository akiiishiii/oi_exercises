// 1910.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k, ans = 0, sum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    std::cin >> n >> k;
    for (int i = 1, x; i <= n; i++)
        std::cin >> x, q.push(x);
    int p = (n - 2) % (k - 1) + 2;
    for (int i = 1; i <= p; i++)
        sum += q.top(), q.pop();
    q.push(sum), ans += sum;
    p = (n - p) / (k - 1);
    for (int i = 1; i <= p; i++) {
        sum = 0;
        for (int j = 1; j <= k; j++)
            sum += q.top(), q.pop();
        q.push(sum), ans += sum;
    }
    std::cout << ans << '\n';
    return 0;
}
