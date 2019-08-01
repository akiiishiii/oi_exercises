// 1147.cpp
#include <cstring>
#include <iostream>

long long f[300010], st[300010], sc[300010];
int q[300010], n, s, head, tail;

inline double slope(int j, int k);
inline long long calc(int i, int j);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> s;
    for (int i = 1, t, c; i <= n; i++) {
        std::cin >> t >> c;
        st[i] = st[i - 1] + t;
        sc[i] = sc[i - 1] + c;
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = q[1] = 0;
    head = tail = 1;
    for (int i = 1; i <= n; i++) {
        while (head < tail && slope(q[head], q[head + 1]) <= (s + st[i]))
            head++;
        f[i] = calc(i, q[head]);
        while (head < tail && slope(q[tail - 1], q[tail]) >= slope(q[tail], i))
            tail--;
        q[++tail] = i;
    }
    std::cout << f[n] << '\n';
    return 0;
}

inline double slope(int j, int k) {
    return (1.0 * f[k] - f[j]) / (1.0 * sc[k] - sc[j]);
}

inline long long calc(int i, int j) {
    return f[j] - (s + st[i]) * sc[j] + st[i] * sc[i] + s * sc[n];
}