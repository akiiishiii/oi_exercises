// 1145.cpp
#include <iostream>

int const Maxn = 50005;
int n, l;
int q[Maxn], head, tail;
long long s[Maxn], f[Maxn];

inline long long s1(int a, int b) { return (f[a] + (s[a] + l) * (s[a] + l)) - (f[b] + (s[b] + l) * (s[b] + l)); }
inline long long s2(int a, int b) { return 2 * (s[a] - s[b]); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> l;
    l++;
    for (int i = 1, c; i <= n; i++)
        std::cin >> c, s[i] = s[i - 1] + c;
    for (int i = 1; i <= n; i++)
        s[i] += i;
    head = tail = 0;
    f[0] = 0;
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        while (head < tail - 1 && s1(q[head + 1], q[head]) <= s[i] * s2(q[head + 1], q[head]))
            head++;
        int x = q[head];
        f[i] = f[x] + (s[i] - s[x] - l) * (s[i] - s[x] - l);
        q[tail++] = i;
        for (int j = tail - 2; j > head; j--) {
            x = q[j - 1];
            int y = j[q], z = j[q + 1];
            if (s1(y, x) * s2(z, y) > s1(z, y) * s2(y, x))
                q[j] = q[--tail];
            else
                break;
        }
    }
    std::cout << f[n] << '\n';
    return 0;
}
