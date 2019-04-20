// 1030.cpp
#include <iostream>

int const Maxn = 100010;
int n, t, a[Maxn];
long long s[Maxn], f[Maxn];
int head = 1, tail = 1;
long long q[Maxn];

inline long double slope(int j, int k) {
    return ((f[j] - s[j] * j) - (f[k] - s[k] * k)) / double(k - j);
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> t;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], s[i] = s[i - 1] + a[i];
    f[0] = q[1] = 0;
    for (int i = 1; i <= n; i++) {
        while (head < tail && (slope(q[head], q[head + 1]) <= s[i]))
            head++;
        f[i] = f[q[head]] + (s[i] - s[q[head]]) * q[head] - t;
        while (head < tail && slope(q[tail - 1], q[tail]) >= slope(q[tail], i))
            tail--;
        q[++tail] = i;
    }
    std::cout << f[n] << '\n';
    return 0;
}