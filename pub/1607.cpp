// 1607.cpp
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>

struct homework {
    int deadline;
    int score;
};

struct compare : public std::binary_function<homework, homework, bool> {
    bool operator()(homework const &a, homework const &b) { return a.deadline > b.deadline; }
};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, ans = 0;
    std::vector<homework> vh;
    std::priority_queue<int> q;
    std::cin >> n;
    vh.resize(n);
    for (std::vector<homework>::iterator it = vh.begin(); it != vh.end(); it++)
        std::cin >> it->deadline >> it->score;
    std::sort(vh.begin(), vh.end(), compare());
    int maxdeadline = vh[0].deadline, i = 0;
    while (maxdeadline) {
        while (vh[i].deadline == maxdeadline) {
            q.push(vh[i].score);
            i++;
        }
        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
        maxdeadline--;
    }
    std::cout << ans << '\n';
    return 0;
}