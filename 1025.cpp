// 1025.cpp
#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    int a[3];
    std::cin >> a[0] >> a[1] >> a[2];
    std::sort(a, a + 3);
    std::cout << a[2] << ' ' << a[1] << ' ' << a[0] << std::endl;
    return 0;
}
