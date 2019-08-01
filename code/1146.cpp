// 1146.cpp
#include <iostream>

int const Maxn = 20010;
long long tot, ans = 1e17, s[Maxn], dis[Maxn];
int w[Maxn], d[Maxn], q[Maxn];
int head, tail, n;

inline double slope(int j, int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> w[i] >> d[i];
    for (int i = n; i; --i)
        tot += w[i] * (dis[i] = dis[i + 1] + d[i]);
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + w[i];
    head = tail = 1;
    for (int i = 1; i <= n; ++i) {
        while (head < tail && slope(q[head], q[head + 1]) > dis[i])
            head++;
        ans = std::min(ans, tot - s[q[head]] * dis[q[head]] -
                                (s[i] - s[q[head]]) * dis[i]);
        while (head < tail && slope(q[tail - 1], q[tail]) <= slope(q[tail], i))
            tail--;
        q[++tail] = i;
    }
    std::cout << ans << '\n';
    return 0;
}

inline double slope(int j, int k) {
    return (1.0 * s[j] * dis[j] - s[k] * dis[k]) / (1.0 * s[j] - s[k]);
}