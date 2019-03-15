// 2420.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, nim = 0, num = 0;
    std::cin >> n;
    for (int i = 1, x; i <= n; i++) {
        std::cin >> x;
        num += (x > 1);
        nim ^= x;
    }
    std::cout << (((!num && !nim) || (num && nim)) ? "win\n" : "lose\n");
    return 0;
}