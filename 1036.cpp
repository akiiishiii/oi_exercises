// 1036.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, num, max;
    std::cin >> n >> num;
    max = num;
    for (int i = 1; i < n; i++) {
        std::cin >> num;
        max = max < num ? num : max;
    }
    std::cout << max << std::endl;
    return 0;
}
