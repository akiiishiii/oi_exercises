// 1060.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, tot = 1;
    std::cin >> n;
    for (int i = 1; i < n; i++)
        tot = 2 * (tot + 1);
    std::cout << tot << std::endl;
    return 0;
}
