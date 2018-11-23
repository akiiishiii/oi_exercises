// 1233.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

int const Maxn = 50005;

struct st {
    int x;
    int n;
    bool operator<(st const &s) const { return x < s.x; }
} a[Maxn];

int s[Maxn], f[Maxn][8], c[Maxn][8], ans[8] = {0};
int r = 0, n;

inline int lowbit(int x) { return x & (-x); }
void plus(int a[], int s[]);
void add(int x, int d[]);
void sum(int x, int d[]);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].x;
        a[i].n = i;
        f[i][0] = f[i][1] = 1;
    }
    std::sort(a + 1, a + n + 1);
    a[0].x = 0;
    for (int i = 1; i <= n; i++)
        if (a[i].x == a[i - 1].x)
            s[a[i].n] = r;
        else
            s[a[i].n] = ++r;
    for (int i = 2; i <= 5; i++) {
        for (int j = 1; j <= r; j++)
            memset(c[j], 0, sizeof(c[j]));
        add(s[i - 1], f[i - 1]);
        memset(f[i - 1], 0, sizeof(f[i - 1]));
        for (int j = i; j <= n; j++) {
            add(s[j], f[j]);
            memset(f[j], 0, sizeof(f[j]));
            sum(s[j] - 1, f[j]);
        }
    }
    for (int i = 5; i <= n; i++)
        plus(ans, f[i]);
    std::cout << ans[ans[0]];
    for (int i = ans[0] - 1; i >= 1; i--)
        for (int j = 1000; j > 0; j /= 10)
            std::cout << ans[i] / j % 10;
    std::cout.put('\n');
    return 0;
}

void plus(int a[], int s[]) {
    if (a[0] < s[0])
        a[0] = s[0];
    for (int i = 1; i <= a[0]; i++) {
        a[i] += s[i];
        a[i + 1] += a[i] / 10000;
        a[i] %= 10000;
    }
    if (a[a[0] + 1] > 0)
        a[0]++;
}

void add(int x, int d[]) {
    for (int i = x; i <= r; i += lowbit(i))
        plus(c[i], d);
}

void sum(int x, int d[]) {
    for (int i = x; i > 0; i -= lowbit(i))
        plus(d, c[i]);
}