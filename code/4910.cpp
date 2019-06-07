// 4910.cpp
#include <algorithm>
#include <iostream>

int n, m, q, u, v, t, dlt;
int a[100001], b[4][7000001], head[4], tmp[4];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        b[1][n - i + 1] = a[i];
    head[1] = head[2] = head[3] = 1;
    tmp[1] = n, tmp[2] = tmp[3] = 0;
    dlt = 0;
    for (int i = 1; i <= m; i++) {
        int ans = -2000000000, num = 0;
        for (int j = 1; j <= 3; j++)
            if (head[j] <= tmp[j] && b[j][head[j]] > ans)
                ans = b[j][head[j]], num = j;
        if (i % t == 0)
            std::cout << ans + dlt << ' ';
        head[num]++;
        b[2][++tmp[2]] = (long long)(ans + dlt) * u / v - dlt - q;
        b[3][++tmp[3]] = ans + dlt - (long long)(ans + dlt) * u / v - dlt - q;
        dlt = dlt + q;
    }
    std::cout << '\n';
    for (int i = 1; i <= n + m; i++) {
        int ans = -2000000000, num = 0;
        for (int j = 1; j <= 3; j++)
            if (head[j] <= tmp[j] && b[j][head[j]] > ans)
                ans = b[j][head[j]], num = j;
        if (i % t == 0)
            std::cout << ans + dlt << ' ';
        head[num]++;
    }
    return 0;
}