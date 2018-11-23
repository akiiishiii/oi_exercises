// 1231.cpp
#include <iostream>

int c[2][50005], m[50005];

inline int lowbit(int const x) { return x & (-x); }
void add(int x, int d, int q);
int ask(int x, int q);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        std::cin >> m[i];
    for (int i = 1; i <= n; i++)
        add(m[i], 1, 1);
    for (int i = 1; i <= n; i++) {
        add(m[i], -1, 1);
        ans += ask(m[i] - 1, 0) * ask(m[i] - 1, 1);
        add(m[i], 1, 0);
    }
    std::cout << ans << '\n';
    return 0;
}

void add(int x, int d, int q) {
    for (int i = x; i <= 50000; i += lowbit(i))
        c[q][i] += d;
}

int ask(int x, int q) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[q][i];
    return ans;
}
