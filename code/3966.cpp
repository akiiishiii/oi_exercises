// 3966.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    std::cout << (n % (k + 1) ? 1 : 2) << '\n';
    return 0;
}