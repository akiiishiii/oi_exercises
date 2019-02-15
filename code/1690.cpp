// 1690.cpp
#include <iostream>
#include <cstring>

int const Maxn = 1005;
int deg[Maxn], n, m;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        memset(deg, 0, sizeof deg);
        int cnt = 0;
        std::cin >> n >> m;
        for (int i = 1, x, y; i <= m; i++)
            std::cin >> x >> y, deg[x]++, deg[y]++;
        for (int i = 1; i <= n; i++)
            if (!deg[i]) {
                cnt = 1;
                break;
            } else if (deg[i] & 1)
                cnt++;
        std::cout << ((cnt > 2 || cnt == 1) ? "No" : "Yes") << '\n';
    }
    return 0;
}