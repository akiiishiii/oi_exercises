// 1642.cpp
#include <cstring>
#include <iostream>

int n, ans = 0;
int mat[305][305], arr[305];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> mat[i][j];
    for (int i = 1; i <= n; i++) {
        memset(arr, 0, sizeof(arr));
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= n; k++)
                arr[k] = arr[k] + mat[j][k];
            int tmp = 0, maxx = 0;
            for (int k = 1; k <= n; k++) {
                if (tmp > 0)
                    tmp += arr[k];
                else
                    tmp = arr[k];
                maxx = std::max(tmp, maxx);
            }
            ans = std::max(ans, maxx);
        }
    }
    std::cout << ans << '\n';
    return 0;
}