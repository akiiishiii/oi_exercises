// 1140.cpp
#include <iostream>
#include <iomanip>

int const SIZE = 100005;
int head[SIZE], ver[SIZE << 1], Next[SIZE << 1];
int tot, cnt, top, num, n, s, t, ans1, ans2;
double k;
int dp[SIZE][2], p[SIZE], prt[SIZE];
bool ins[SIZE];

template <typename T1, typename T2>
auto max(T1 const &a, T2 const &b) -> decltype(a > b ? a : b) { return a > b ? a : b; }
template <typename T1, typename T2>
auto min(T1 const &a, T2 const &b) -> decltype(a < b ? a : b) { return a < b ? a : b; }
inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = cnt; }
inline int search(int x) { return ((prt[x] == x) ? (x) : (prt[x] = search(prt[x]))); }
void dfs(int u, int f);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> p[i], prt[i] = i;
    for (int i = 1, a, b; i <= n; i++) {
        std::cin >> a >> b;
        a++, b++;
        int p1 = ::search(a), p2 = ::search(b);
        if (p1 == p2) {
            s = a, t = b;
            continue;
        }
        prt[p1] = p2;
        ::add(a, b), ::add(b, a);
    }
    std::cin >> k;
    dfs(s,s);
    ans1 = dp[s][0];
    dfs(t,t);
    ans2 = dp[t][0];
    std::cout << std::fixed << std::setprecision(1) << double(::max(ans1, ans2)) * k << '\n';
    return 0;
}

void dfs(int u, int f) {
    dp[u][1] = p[u], dp[u][0] = 0;
    for (int i = head[u]; i; i = Next[i]) {
        int v = ver[i];
        if (v == f)
            continue;
        dfs(v, u);
        dp[u][1] += dp[v][0];
        dp[u][0] += ::max(dp[v][0], dp[v][1]);
    }
}