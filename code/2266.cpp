// 2266.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, f[2][4] = {{1, 1, 1, 2}, {0, 0, 0, 1}};
    std::cin >> n;
    for(int i = 3; i <= n; i++) {
        f[i & 1][0] = f[1 - (i & 1)][3] % 10000;
        f[i & 1][1] = (f[1 - (i & 1)][0] + f[1 - (i & 1)][2]) % 10000;
        f[i & 1][2] = (f[1 - (i & 1)][0] + f[1 - (i & 1)][1]) % 10000;
        f[i & 1][3] = (f[1 - (i & 1)][0] + f[1 - (i & 1)][1] + f[1 - (i & 1)][2] + f[1 - (i & 1)][3]) % 10000;
    }
    std::cout << f[n & 1][3] % 10000 << '\n';
    return 0;
}
