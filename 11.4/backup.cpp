// backup.cpp
#include <iostream>
#include <fstream>
#include <queue>
#include <utility>

//#define debug

#ifndef debug

std::ifstream in("backup.in");
std::ofstream out("backup.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > q;
int n, k, ans = 0, d[100005], prev[100005], next[100005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> k;
    int x, y;
    in >> x;
    for (int i = 2; i <= n; i++) {
        in >> y;
        d[i] = y - x;
        x = y;
        q.push(std::make_pair(d[i], i));
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    prev[2] = next[n] = 0;
    while (k--) {
        while (q.top().first != d[q.top().second])
            q.pop();
        int k = q.top().second;
        int l = prev[k], r = next[k];
        q.pop();
        ans += d[k];
        if (l && r)
            d[k] = d[l] + d[r] - d[k];
        else
            d[k] = 0x3f3f3f3f;
        prev[next[r]] = k;
        next[prev[l]] = k;
        next[k] = next[r];
        prev[k] = prev[l];
        d[l] = d[r] = 0x3f3f3f3f;
        q.push(std::make_pair(d[k], k));
    }
    out << ans << '\n';
    return 0;
}