// 1242.cpp
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    int n;
    std::vector<int> f;
    std::cin >> n;
    f.resize(n + 5);
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for (std::vector<int>::iterator it = f.begin() + 3; it != f.end(); it++)
        *it = *(it - 1) + *(it - 2);
    std::cout << f[n] << std::endl;
    return 0;
}