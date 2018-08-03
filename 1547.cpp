// 1547.cpp
#include <iostream>
#include <cstring>

int main(int argc, char const * argv[]) {
    int prt[105], n, k, ans = 0;
    memset(prt, -1, sizeof prt);
    std::cin >> n >> k;
    for (int i = 0, ki, kj; i < k; i++) {
        std::cin >> ki >> kj;
        prt[kj] = ki;
    }
    for (int i = 1; i <= n; i++)
        if (prt[i] == -1)
            ans++;
    std::cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        if (prt[i] == -1)
            std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}