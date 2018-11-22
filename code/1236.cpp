// 1236.cpp
#include <iostream>

int n, a[1000005];
long long k[1000005] = {0};

inline int lowbit(int x) { return x & (-x); }

void add(int x, int d);
long long sum(int x);

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1, k, l, r, x; i <= q; i++) {
        std::cin >> k;
        if (k == 1) {
            std::cin >> l >> r >> x;
            add(l, x);
            add(r + 1, -x);
        } else {
            std::cin >> x;
            std::cout << sum(x) + a[x] << "\n";
        }
    }
    return 0;
}

void add(int x, int d) {
    for (int i = x; i <= n; i += lowbit(i))
        k[i] += d;
}

long long sum(int x) {
    long long ans;
    ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += k[i];
    return ans;
}