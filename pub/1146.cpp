// 1146.cpp
#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    int a[800] = {0}, n;
    a[0] = a[1] = 1;
    std::cin >> n;
    for (int i = n; i > 1; i--) {
        for (int j = 1; j <= a[0]; j++)
            a[j] *= i;
        for (int j = 1; j <= a[0]; j++) {
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
        }
        while (a[a[0] + 1] > 0) {
            a[0]++;
            a[a[0] + 1] += a[a[0]] / 10;
            a[a[0]] %= 10;
        }
    }
    if (!a[0])
        std::cout << 0;
    else
        for (int i = a[0]; i > 0; i--)
            std::cout << a[i];
    std::cout << std::endl;
    return 0;
}