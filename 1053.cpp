// 1053.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            std::cout.put(' ');
        for (int j = 0; j < 2 * n - 1 - 2 * i; j++)
            std::cout.put('*');
        std::cout << std::endl;
    }
    return 0;
}
