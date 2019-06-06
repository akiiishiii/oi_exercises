// 1398.cpp
#include <iostream>

int n, p;
int a[100010], s[100010], w[100010];
long long ans;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (std::cin >> n && n) {
        ans = p = 0;
        for (int i = 1; i <= n; i++)
            std::cin >> a[i];
        a[n + 1] = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (a[i] > s[p])
                s[++p] = a[i], w[p] = 1;
            else {
                int width = 0;
                while (s[p] > a[i]) {
                    width += w[p];
                    ans = std::max(ans, (long long)width * s[p--]);
                }
                s[++p] = a[i], w[p] = width + 1;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}