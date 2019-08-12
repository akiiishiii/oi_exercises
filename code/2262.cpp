// 2262.cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

int const Maxn = 10005;
std::string s[Maxn];
int a[Maxn], b[Maxn], p[Maxn], lena = 1, lenb = 1;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, ans = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> s[i];
    std::sort(s + 1, s + n + 1);
    for (int i = 1; i <= m; i++) {
        std::string c;
        std::cin >> c;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (s[mid] < c)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if (!s[l].find(c, 0))
            ans++;
    }
    std::cout << ans << '\n';
    if (n <= 2) {
        std::cout << n << '\n';
        return 0;
    }
    a[1] = 1, b[1] = 2;
    for (int i = 3; i <= n; i++) {
        memset(p, 0, sizeof(p));
        int lenc = std::max(lena, lenb);
        for (int j = 1; j <= lenc; j++) {
            p[j] += a[j] + b[j];
            p[j + 1] += p[j] / 10;
            p[j] %= 10;
        }
        if (p[lenc + 1])
            lenc++;
        lena = lenb;
        for (int j = 1; j <= lena; j++)
            a[j] = b[j];
        lenb = lenc;
        for (int j = 1; j <= lenb; j++)
            b[j] = p[j];
    }
    for (int i = lenb; i >= 1; i--)
        std::cout << b[i];
    std::cout << '\n';
    return 0;
}