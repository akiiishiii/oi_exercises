// 1359.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    int n, arr[1005] = {-1}, f[1005], maxi = 0;
    f[0] = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        f[i] = arr[i];
    }
    for (int i = 1; i <= n; i++) {
        int maxj = 0;
        for (int j = 1; j < i; j++)
            if (arr[j] < arr[i])
                maxj = f[j] > maxj ? f[j] : maxj;
        f[i] = maxj + arr[i];
    }
    for (int i = 1; i <= n; i++)
        maxi = f[i] > maxi ? f[i] : maxi;
    std::cout << maxi << std::endl;
    return 0;
}
