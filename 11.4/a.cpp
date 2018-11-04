#include <iostream>
#include <queue>
#include <utility>

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > q;
int n, k, dis[100005], pre[100005], nxt[100005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> k;
    int x, y;
    std::cin >> x;
    for (int i = 2; i <= n; i++) {
        std::cin >> y;
        dis[i] = y - x;
        x = y;
        q.push(std::make_pair(dis[i], i));
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    int ans = 0;
    pre[2] = nxt[n] = 0;
    while (k--) {
        while (q.top().first != dis[q.top().second])
            q.pop();
        int k = q.top().second;
        int l = pre[k], r = nxt[k];
        q.pop();
        ans += dis[k];
        if (l && r)
            dis[k] = dis[l] + dis[r] - dis[k];
        else
            dis[k] = 0x3f3f3f3f;
        pre[nxt[r]] = k;
        nxt[pre[l]] = k;
        nxt[k] = nxt[r];
        pre[k] = pre[l];
        dis[l] = dis[r] = 0x3f3f3f3f;
        q.push(std::make_pair(dis[k], k));
    }
    std::cout << ans << '\n';
    return 0;
}