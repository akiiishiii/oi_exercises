// 1266.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, ans = 0;
    std::cin >> n;
    for (int i = 1; i < n; i += 2) {
        ans += n - i;
        ans %= 12345;
    }
    std::cout << ans % 12345 << std::endl;
    return 0;
}