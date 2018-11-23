// 1230.cpp
#include <iostream>
#include <cmath>

int const Maxn = 100005;
int n;
long long a[Maxn], c[Maxn], prt[Maxn];

int lowbit(int const x) { return x & (-x); }
int search(int const x) { return (prt[x] == x) ? x : (prt[x] = search(prt[x])); }
void add(int x, long long d);
long long sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], add(i, a[i]), prt[i] = i;
    std::cin >> m;
    for (int i = 1, k, l, r; i <= m; i++) {
        std::cin >> k >> l >> r;
        if (k)
            std::cout << sum(r) - sum(l - 1) << '\n';
        else {
            for (int i = l, t; i <= r; i++) {
                i = search(i);
                if (i > r)
                    break;
                add(i, int(t = sqrt(a[i])) - a[i]);
                a[i] = t;
                if (a[i] == 1)
                    prt[i] = prt[i + 1];
            }
        }
    }
    return 0;
}

void add(int x, long long d) {
    for (int i = x; i <= Maxn; i += lowbit(i))
        c[i] += d;
    return;
}

long long sum(int x) {
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}