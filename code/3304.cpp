// 3304.cpp
#include <iostream>
using namespace std;

int const Maxn = 10000005;
char s[Maxn], a[Maxn];
int p[Maxn] = {0};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int len, n = 0, mx, id, ans = 0;
    std::cin >> len >> a;
    s[0] = '$';
    for (int i = 0; i < len; ++i)
        s[++n] = '#', s[++n] = a[i];
    for (int i = 1; i <= n; ++i) {
        if (mx > i)
            p[i] = std::min(p[2 * id - i], mx - i);
        else
            p[i] = 1;
        while (s[i - p[i]] == s[i + p[i]])
            ++p[i];
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
    for (int i = 1; i <= n; i += 2) {
        int l = (i - p[i] + 1 + i) / 2;
        if (!(l % 2))
            ++l;
        while (l <= i && l + p[l] < i)
            l += 2;
        ans = std::max(ans, ((i - l) / 2) * 4);
    }
    std::cout << ans << '\n';
    return 0;
}