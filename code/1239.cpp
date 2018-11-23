// 1239.cpp
#include <iostream>
#include <cstring>

int const Maxn = 200005;
int n;
int c[Maxn], a[Maxn], l[Maxn], r[Maxn];

inline int lowbit(int const x) { return x & (-x); }
void add(int x);
int sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = n; i > 0; i--) {
        int k = sum(a[i]);
        add(a[i]);
        r[i] = k;
    }
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        int k = sum(a[i]);
        add(a[i]);
        l[i] = k;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (long long)(i - 1 - l[i]) * (n - i - r[i]);
    std::cout << ans << ' ';
    ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (long long)l[i] * r[i];
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