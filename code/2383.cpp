// 2383.cpp
#include <iostream>

int const Maxn = 401;
int n, m, ans=0xcfcfcfcf;
int s[Maxn][Maxn], b[Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            std::cin >> c;
            s[i][j] = ((c == '1') ? 1 : -1);
        }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++)
            b[k] = 0;
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= m; k++)
                b[k] += s[j][k];
            int tot = b[1];
            ans = std::max(tot, ans);
            for (int j = 2; j <= m; j++)
                if(tot >= 0)
                    tot += b[j], ans = std::max(tot, ans);
                else
                    tot = b[j], ans = std::max(tot, ans);
        }
    }
    std::cout << ans << '\n';
    return 0;
}
