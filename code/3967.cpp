// 3967.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, ans = 0;
    std::cin >> n;
    for (int i = 1, x; i <= n; i++)
        std::cin >> x, ans ^= x;
    std::cout << (ans ? 1 : 2) << '\n';
    return 0;
}