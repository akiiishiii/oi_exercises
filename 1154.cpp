// 1154.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int k;
    long long res = 0;
    std::cin >> k;
    for (int i = 1, tot = 1; true; i++)
        for (int j = 1; j <= i; j++, tot++, res += i)
            if (tot == k) {
                std::cout << res + i << std::endl;
                return 0;
            }
    return 0;
}