// 1564.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<int> va, vb;

struct compare : std::binary_function<std::pair<int, int>, std::pair<int, int>, bool> {
    bool operator() (const std::pair<int, int> &a, const std::pair<int, int> &b) const { return va[a.first] + vb[a.second] > va[b.first] + vb[b.second]; }
};

int main(int argc, char const *argv[]) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, compare> q;
    int n;
    std::cin >> n;
    va.resize(n);
    vb.resize(n);
    for (int i = 0; i < n; i++)
        std::cin >> va[i];
    for (int i = 0; i < n; i++)
        std::cin >> vb[i];
    std::sort(va.begin(), va.end());
    std::sort(vb.begin(), vb.end());
    for (int i = 0; i < n; i++)
        q.push(std::make_pair(0, i));
    for (int i = 0; i < n && !q.empty(); i++) {
        std::cout << va[q.top().first] + vb[q.top().second] << ' ';
        q.push(std::make_pair(q.top().first + 1, q.top().second));
        q.pop();
    }
    std::cout << '\n';
    return 0;
}
