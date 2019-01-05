// 1700.cpp
#include <iostream>

struct point {
    int x, y;
} ps[705];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> ps[i].x >> ps[i].y;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            int cnt = 2;
            for (int k = j + 1; k <= n; k++)
                if (!((ps[i].x - ps[k].x) * (ps[j].y - ps[k].y) - (ps[j].x - ps[k].x) * (ps[i].y - ps[k].y)))
                    cnt++;
            if (cnt > ans)
                ans = cnt;
        }
    std::cout << ans << '\n';
    return 0;
}
