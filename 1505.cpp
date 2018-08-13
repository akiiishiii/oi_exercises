// 1505.cpp
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
    int arr[5010] = {0}, f[5010] = {1}, t[5010] = {1}, n, maxx = 0, ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        f[i] = t[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] > arr[i]) {
                if (f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                    t[i] = t[j];
                } else if (f[j] + 1 == f[i])
                    t[i] += t[j];
            }
            if (arr[j] == arr[i]) {
                t[j] = 0;
                f[j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        maxx = std::max(maxx, f[i]);
    for (int i = 1; i <= n; i++)
        if (f[i] == maxx)
            ans += t[i];
    std::cout << maxx << ' ' << ans << '\n';
    return 0;
}
