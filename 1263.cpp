// 1263.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::vector<int> num;
    int n;
    std::cin >> n;
    num.resize(n);
    for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++)
        std::cin >> *it;
    std::sort(num.begin(), num.end());
    for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
    for (std::vector<int>::iterator it = num.end() - 1; it != num.begin() - 1; it--)
        std::cout << *it << ' ';
    std::cout << std::endl;
    return 0;
}