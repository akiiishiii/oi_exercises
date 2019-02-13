// 1088.cpp
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
    std::cout << *std::max_element(num.begin(), num.end()) << ' ' << int(std::max_element(num.begin(), num.end()) - num.begin() + 1) << std::endl;
    return 0;
}
