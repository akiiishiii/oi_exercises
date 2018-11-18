// 1232.cpp
#include <algorithm>
#include <iostream>

struct point {
    int x;
    int y;
    bool operator<(point const &p) const { return (x < p.x || (x == p.x && y < p.y)); }
} a[1000010];

int maxn;
long long c[1005]= {0};

template <typename T>
inline T lowbit(T const &x) { return x & (-x); }
long long sum(int x);
void add(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t, tmp = 0, n, m, k;
    long long ans;
    std::cin >> t;
    while (t--) {
        ans = 0;
        std::cin >> n >> m >> k;
        for (int i = 1; i <= m; i++)
            c[i] = 0;
        maxn = m;
        for (int i = 1; i <= k; i++)
            std::cin >> a[i].x >> a[i].y;
        std::sort(a + 1, a + 1 + k);
        for (int i = 1; i <= k; i++) {
            ans += sum(a[i].y + 1);
            add(a[i].y);
        }
        std::cout << "Test case " << ++tmp << ": " << ans << '\n';
    }
    return 0;
}

long long sum(int x) {
    long long res = 0;
    for (int i = x; i <= maxn; i += lowbit(i))
        res += c[i];
    return res;
}

void add(int x) {
    for (int i = x; i > 0; i -= lowbit(i))
        c[i]++;
}