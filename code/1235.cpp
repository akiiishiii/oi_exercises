// 1235.cpp
#include <iostream>

int n;
long long c[1000005] = {0};

template <typename T>
inline T lowbit(T const x) { return x & (-x); }
void add(int x, int d);
long long sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int q;
    std::cin >> n >> q;
    for (int i = 1, a; i <= n; i++) {
        std::cin >> a;
        add(i, a);
    }
    for (int i = 1, k, x, y; i <= q; i++) {
        std::cin >> k >> x >> y;
        if (k == 1)
            add(x, y);
        else
            std::cout << sum(y) - sum(x - 1) << '\n';
    }
    return 0;
}

void add(int x, int d) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += d;
}

long long sum(int x) {
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}