// 1142.cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>

const int M = 19931117, N = 1000010;
int prt[N], n;
int indeg[N], p[N], dp[N][2];
int head[N], ver[N], Next[N], tot;
std::vector<std::pair<int, int> > ent;
int q[N], l, r;

template <typename T1, typename T2>
auto max(T1 const &a, T2 const &b) -> decltype(a > b ? a : b) { return a > b ? a : b; }
template <typename T1, typename T2>
auto min(T1 const &a, T2 const &b) -> decltype(a < b ? a : b) { return a < b ? a : b; }
int search(int a) { return prt[a] == a ? a : (prt[a] = search(prt[a])); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (search(i) != search(x)) {
            p[i] = x, prt[search(i)] = search(x), ++indeg[x];
            ver[tot] = i, Next[tot] = head[x];
            head[x] = tot++;
        } else
            p[i] = -1, ent.push_back(std::make_pair(i, x));
    }
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q[r++] = i;
    while (l != r) {
        int c = q[l++];
        if (head[c] == -1)
        dp[c][0] = 0, dp[c][1] = -M;
        else {
            dp[c][0] = 0, dp[c][1] = 1;
            bool zr = false;
            for (int p = head[c]; p != -1; p = Next[p]) {
                int t = ver[p], rr = ::max(dp[t][0], dp[t][1]);
                if (dp[t][0] == rr)
                    zr = true;
                dp[c][0] += rr, dp[c][1] += rr;
            }
            if (!zr) {
                int dlt = M;
                for (int p = head[c]; p != -1; p = Next[p]) {
                    int t = ver[p];
                    dlt = ::min(dlt, dp[t][1] - dp[t][0]);
                }
                dp[c][1] -= dlt;
            }
        }
        if (p[c] != -1) {
            --indeg[p[c]];
            if (!indeg[p[c]])
                q[r++] = p[c];
        }
    }
    int ans = 0;
    for (std::vector<std::pair<int, int> >::iterator it = ent.begin(); it != ent.end(); ++it) {
        int x = it->first, y = it->second;
        int tmp = dp[x][1], sum = 0;
        for (int p = head[y]; p != -1; p = Next[p])
            sum += dp[ver[p]][1];
        if (dp[y][1] < sum + 1) {
            dp[y][1] = sum + 1;
            int py = p[y];
            while (py != -1) {
                int t0 = dp[py][0], t1 = dp[py][1];
                if (head[py] == -1)
                    dp[py][0] = 0, dp[py][1] = -M;
                else {
                    dp[py][0] = 0, dp[py][1] = 1;
                    bool zr = false;
                    for (int p = head[py]; p != -1; p = Next[p]) {
                        int t = ver[p], rr = ::max(dp[t][0], dp[t][1]);
                        if (dp[t][0] == rr)
                            zr = true;
                        dp[py][0] += rr, dp[py][1] += rr;
                    }
                    if (!zr) {
                        int dlt = M;
                        for (int p = head[py]; p != -1; p = Next[p]) {
                            int t = ver[p];
                            dlt = ::min(dlt, dp[t][1] - dp[t][0]);
                        }
                        dp[py][1] -= dlt;
                    }
                }
                if (t0 == dp[py][0] && t1 == dp[py][1])
                    break;
                else
                    py = p[py];
            }
        }
        tmp = ::max(tmp, dp[x][0]), ans += tmp;
    }
    std::cout << ans << '\n';
    return 0;
}