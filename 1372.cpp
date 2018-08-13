// 1372.cpp
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[]) {
    int f[1001], a[21] = {0}, n, m;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= a[i]; j--)
            f[j] += f[j - a[i]];
    std::cout << f[m] << '\n';
    return 0;
}
