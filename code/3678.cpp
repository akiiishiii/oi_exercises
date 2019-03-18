// 3678.cpp
#include <iostream>

int (*nmsl)();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    nmsl()();
    return 0;
}