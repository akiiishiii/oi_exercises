// 1265copy.cpp
#include <iostream>

int main() {
    long long x, y, z, i, k, a[1001] = {0}, sum = 0;
    std::cin >> x >> y >> z;
    a[1] = 1;
    for (i = 1; i <= z + 1; i++)
        for (k = 1; k <= z + 1; k++)
            a[i + k * x + 2] += a[i] * y;
    for (i = 1; i <= z + 1; i++)
        sum += a[i];
    std::cout << sum << std::endl;
    return 0;
}