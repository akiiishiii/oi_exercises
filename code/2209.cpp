// 2209.cpp
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int n, m, s[200005], ans[200005], maxx = 0xcfcfcfcf;

struct cmp : public std::binary_function<int, int, bool> {
    bool operator()(int const &a, int const &b) const { return s[a] > s[b]; }
};

std::priority_queue<int, std::vector<int>, cmp> q;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1, x; i <= n; ++i)
        std::cin >> x, s[i] = s[i - 1] + x;
    q.push(0);
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && q.top() < i - m)
            q.pop();
        ans[i] = s[i] - s[q.top()];
        maxx = std::max(ans[i], maxx);
        q.push(i);
    }
    std::cout << maxx << '\n';
    return 0;
}