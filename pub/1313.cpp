// 1313.cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char const * argv[]) {
    int n;
    std::vector<int> a;
    std::cin >> n;
    a.resize(n);
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cin >> *it;
    std::cout << *std::max_element(a.begin(), a.end()) << ' '
              << *std::min_element(a.begin(), a.end()) << std::endl;
    return 0;
}