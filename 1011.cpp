// 1011.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int a1, a2, n;
    std::cin >> a1 >> a2 >> n;
    int k = a2 - a1;
    for (int i = 2; i < n; i++)
        a2 += k;
    std::cout << a2 << std::endl;
    return 0;
}
