// 2458.cpp
#include <iostream>
#include <bitset>

int const Maxn = 2020, dx[5] = {0, 1, 0, -1, 0}, dy[5] = {0, 0, 1, 0, -1};
int n, px, py, ans;
char s[Maxn];
std::bitset<Maxn> a[Maxn];

bool gauss(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> (s + 1);
        for (int j = 1; j <= n; j++)
            a[(i - 1) * n + j][n * n + 1] = bool(s[j] == 'w');
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 0; k <= 4; k++) {
                px = i + dx[k], py = j + dy[k];
                if (px >= 1 && px <= n & py >= 1 && py <= n)
                    a[(px - 1) * n + py][(i - 1) * n + j] = 1;
            }
    if (!gauss(n * n))
        std::cout << "inf\n";
    else
        std::cout << ans << '\n';
    return 0;
}

bool gauss(int x) {
    int now = 1;
    for (int j = 1, i; j <= x; j++) {
        for (i = now; i <= x; i++)
            if (a[i][j])
                break;
        if (i > x)
            continue;
        if (i != now)
            swap(a[i], a[now]);
        for (i = 1; i <= x; i++)
            if (i != now && a[i][j])
                a[i] ^= a[now];
        now++;
    }
    for (int i = now; i <= x; i++)
        if (a[i][x + 1])
            return false;
    for (int i = 1; i <= x; i++)
        ans += a[i][x + 1];
    return true;
}