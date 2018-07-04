// 1129.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int q;
    unsigned long long ft[95] = {0, 0, 1, 1};
    for (int i = 4; i <= 93; i++)
        ft[i] = ft[i - 1] + ft[i - 2];
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        unsigned long long a, b;
        std::cin >> a >> b;
        std::cout << ft[b] - ft[a - 1] << std::endl;
    }
        return 0;
}