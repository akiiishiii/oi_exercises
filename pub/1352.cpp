// 1355.cpp
#include <iostream>

template <typename T>
inline T max(const T a, const T b) { return a > b ? a : b;}

int main(int argc, const char * argv[]) {
    int n, arr[1010] = {0}, f[1010], g[1010], maxp = 0;
    std::cin >> n;
    f[0] = g[n + 1] = 0;
    for (int i = 1; i <= n; i++)
        std::cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        int maxf = 0;
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                maxf = f[j] > maxf ? f[j] : maxf;
        f[i] = maxf + 1;
    }
    for (int i = n; i >= 1; i--) {
        int maxg = 0;
        for (int j = n + 1; j > i; j--)
            if (arr[i] > arr[j])
                maxg = g[j] > maxg ? g[j] : maxg;
        g[i] = maxg + 1;
    }
    for (int i = 1; i <= n; i++)
        maxp = f[i] + g[i] > maxp ? f[i] + g[i] : maxp;
    std::cout << maxp - 1 << std::endl;
    return 0;
}
