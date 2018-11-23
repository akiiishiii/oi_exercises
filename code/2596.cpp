// 2596.cpp
#include <iostream>
#include <cstring>

int const Maxn = 200005;
int n;
int c[Maxn], val[Maxn], r[Maxn];

inline int lowbit(int const x) { return x & (-x); }
void add(int x);
int sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> val[i];
    for (int i = n; i >= 1; i--) {
        r[i] = n - i - sum(val[i] - 1);
        ans += (long long)r[i] * (r[i] - 1) >> 1;
        add(val[i]);
    }
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        ans -= (long long)sum(val[i] - 1) * r[i];
        add(val[i]);
    }
    std::cout << ans << '\n';
    return 0;
}

void add(int x) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i]++;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}