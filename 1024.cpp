// 1024.cpp
#include <iostream>

int f(int x) { return x > 0 ? x + 1 : x == 0 ? 0 : x - 1;}

int main(int argc, const char * argv[]) {
    int x;
    std::cin >> x;
    std::cout << f(x) << std::endl;
    return 0;
}
