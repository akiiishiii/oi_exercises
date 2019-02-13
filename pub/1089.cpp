// 1089.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::vector<int> num;
    int n, n1 = 0, n2 = 0;
    std::cin >> n;
    num.resize(n);
    for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++)
        std::cin >> *it;
    std::sort(num.begin(), num.end());
    std::vector<int>::iterator it;
    for (it = num.end() - 2; *it == *(it + 1) && it != num.begin(); it--)
        n1++;
    for (it--; *it == *(it + 1) && it != num.begin(); it--)
        n2++;
    std::cout << n1 + 1 << ' ' << n2 + 1 << ' ' << std::unique(num.begin(), num.end()) - num.begin() << std::endl;
    ;
    return 0;
}