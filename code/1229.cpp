// 1229.cpp
#include <iostream>

int const Maxn = 100005;

long long c1[Maxn], c2[Maxn], sum[Maxn];
int a[Maxn], n;

inline int lowbit(int const i) { return i & (-i); }
long long read(long long *a, int x);
void modify(long long *a, int x, long long d);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int q;
    long long ans;
    char ch;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    int s, t, d;
    while (q--) {
        while ((ch = std::cin.get()) != (-1))
            if (ch == 'C' || ch == 'Q')
                break;
        if (ch == 'Q') {
            std::cin >> s >> t;
            ans = sum[t] - sum[s - 1];
            ans += (t + 1) * read(c1, t) - read(c2, t);
            ans -= s * read(c1, s - 1) - read(c2, s - 1);
            std::cout << ans << '\n';
        } else {
            std::cin >> s >> t >> d;
            modify(c1, s, d);
            modify(c1, t + 1, -d);
            modify(c2, s, d * s);
            modify(c2, t + 1, -d * (t + 1));
        }
    }
    return 0;
}

long long read(long long *a, int x) {
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += a[i];
    return ans;
}

void modify(long long *a, int x, long long d) {
    for (int i = x; i <= n; i += lowbit(i))
        a[i] += d;
}