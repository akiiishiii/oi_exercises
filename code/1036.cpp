// 1036.cpp
#include <iostream>

int f[110], w[15], n;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 1; i <= 10; i++)
        std::cin >> w[i];
    std::cin >> n;
    f[1] = w[1];
    for (int i = 2; i <= n; i++) {
        f[i] = 0x3f3f3f3f;
        for (int j = 1; j <= 10; j++) {
            if (i - j < 0)
                break;
            f[i] = std::min(f[i], f[i - j] + w[j]);
        }
    }
    std::cout << f[n] << '\n';
    return 0;
}