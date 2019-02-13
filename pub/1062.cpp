// 1062.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    long long l1 = 0, l2 = 1, l3 = l1 + l2;
    std::cin >> n;
    if (n == 1) {
        std::cout << "0\n";
        return 0;
    } else if (n <= 3) {
        std::cout << "1\n";
        return 0;
    }
    for (int i = 4; i <= n; i++) {
        l1 = l2;
        l2 = l3;
        l3 = l1 + l2;
    }
    std::cout << l3 << std::endl;
    return 0;
}
