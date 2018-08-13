// 1360.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    int k;
    std::cin >> k;
    for (int times = 0; times < k; times++) {
        int n, arr[1005] = {0}, f[1005], maxi = 0;
        std::cin >> n;
        f[0] = f[n + 1] = 0;
        for (int i = 1; i <= n; i++)
            std::cin >> arr[i];
        for (int i = 1; i <= n; i++) {
            int maxj = 0;
            for (int j = 1; j < i; j++)
                if (arr[j] < arr[i])
                    maxj = f[j] > maxj ? f[j] : maxj;
            f[i] = maxj + 1;
        }
        for (int i = 1; i <= n; i++)
            maxi = f[i] > maxi ? f[i] : maxi;
        for (int i = n; i >= 1; i--) {
            int maxj = 0;
            for (int j = n + 1; j > i; j--)
                if (arr[j] < arr[i])
                    maxj = f[j] > maxj ? f[j] : maxj;
            f[i] = maxj + 1;
        }
        for (int i = 1; i <= n; i++)
            maxi = f[i] > maxi ? f[i] : maxi;
        std::cout << maxi << std::endl;
    }
    return 0;
}