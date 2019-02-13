// 1150.cpp
#include <iostream>

inline int min(int a, int b) { return a < b ? a : b;}

int main(int argc, const char * argv[]) {
    int n, num[3] = {0}, pri[3] = {0}, res[3];
    std::cin >> n;
    for (int i = 0; i < 3; i++) {
        std::cin >> num[i] >> pri[i];
        res[i] = pri[i] * (n / num[i] + (n % num[i] ? 1 : 0));
    }
    std::cout << min(res[0], min(res[1], res[2]));
    return 0;
}