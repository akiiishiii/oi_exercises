// 2057.cpp
#include <cstring>
#include <iostream>

int const Maxn = 1000005;
int n, q[Maxn];
long long f[Maxn], x[Maxn], s[Maxn], sp[Maxn], c[Maxn];

inline double slope(int j, int k);
inline long long calc(int i, int j);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    memset(f, 0x3f, sizeof(f));
    std::cin >> n;
    for (int i = 1, p; i <= n; i++) {
        std::cin >> x[i] >> p >> c[i];
        s[i] = s[i - 1] + p;
        sp[i] = sp[i - 1] + x[i] * p;
    }
    f[0] = 0;
    int head = 1, tail = 1;
    for (int i = 1; i <= n; i++) {
        while (head < tail && (slope(q[head], q[head + 1]) <= x[i]))
            head++;
        f[i] = calc(i, q[head]);
        while (head < tail && slope(q[tail], i) <= slope(q[tail - 1], q[tail]))
            tail--;
        q[++tail] = i;
    }
    std::cout << f[n] << '\n';
    return 0;
}

inline double slope(int j, int k) {
    return (f[k] + sp[k] - f[j] - sp[j] * 1.0) / (s[k] - s[j] * 1.0);
}

inline long long calc(int i, int j) {
    return f[j] + x[i] * (s[i] - s[j]) - (sp[i] - sp[j]) + c[i];
}