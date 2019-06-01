// 2944.cpp
#include <algorithm>
#include <cmath>
#include <iostream>

int n, m, a[200005];
int pos[2000020], last[200005];
int st[200005], f[200005];
int p[200005][20];

int search(int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        if (!pos[a[i] + 1000001]) {
            pos[a[i] + 1000001] = i;
            st[i] = std::max(1, st[i - 1]);
            f[i] = i - st[i] + 1;
        } else {
            st[i] = std::max(pos[a[i] + 1000001] + 1, st[i - 1]);
            f[i] = i - st[i] + 1;
            pos[a[i] + 1000001] = i;
        }
    for (int i = 1; i <= n; ++i)
        p[i][0] = f[i];
    int k = log2(n) + 1;
    for (int j = 1; j <= k; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            p[i][j] = std::max(p[i][j - 1], p[i + (1 << (j - 1))][j - 1]);
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << search(++l, ++r) << '\n';
    }
    return 0;
}

int search(int l, int r) {
    int ll = l, rr = r, mid, ans = r + 1;
    while (ll <= rr) {
        mid = (ll + rr) >> 1;
        if (st[mid] < l)
            ll = mid + 1;
        else {
            ans = mid;
            rr = mid - 1;
        }
    }
    if (ans == r + 1)
        return ans - l;
    int k = log2(r - ans + 1);
    return std::max(std::max(p[ans][k], p[r - (1 << k) + 1][k]), ans - l);
}