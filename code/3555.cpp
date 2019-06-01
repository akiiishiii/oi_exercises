// 3555.cpp
#include <algorithm>
#include <iostream>
#include <queue>

struct node {
    int s, t, pos;
    bool operator<(node const &n) const {
        return ((t == n.t) ? (s < n.s) : (t > n.t));
    }
    static bool cmp(node const &a, node const &b) {
        return ((a.s == b.s) ? (a.t < b.t) : (a.s < b.s));
    }
} nos[50010];

int id[50010];
std::priority_queue<node> q;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, ans = 1;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> nos[i].s >> nos[i].t;
        nos[i].pos = i;
    }
    std::sort(nos + 1, nos + 1 + n, node::cmp);
    q.push(nos[1]);
    id[nos[1].pos] = 1;
    for (int i = 2; i <= n; i++) {
        if (!q.empty() && q.top().t < nos[i].s) {
            id[nos[i].pos] = id[q.top().pos];
            q.pop();
        } else
            id[nos[i].pos] = ++ans;
        q.push(nos[i]);
    }
    std::cout << ans << '\n';
    /*
    for (int i = 1; i <= n; i++)
        std::cout << id[i] << '\n';

    */
    return 0;
}
