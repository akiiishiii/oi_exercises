// 1408.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, f[50005] = {0};
    for (int i = 1, k = 0, kk = 1, t = 1; i <= 50000; i++) {
        f[i] = (f[i - 1] + t) % 10000;
        if (++k == kk) {
            kk++;
            k = 0, t = t * 2 % 10000;
        }
    }
    while (std::cin >> n)
        std::cout << f[n] << '\n';
    return 0;
}