#include <algorithm>
#include <iostream>
#include <functional>

int main() {
    int a[] = {0, 1, 3, 423, 432, 1, 54};
    std::sort(a + 1, a + 1 + 6, std::greater<int>());
    for (int i = 1; i <= 6; i++)
        std::cout << a[i] << ' ';
    std::cout << '\n';
    return 0;
}