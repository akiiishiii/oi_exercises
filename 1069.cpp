// 1069.cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
    int n;
    std::vector<int> a;
    std::cin >> n;
    a.resize(n);
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cin >> *it;
    std::sort(a.begin(), a.end());
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
    return 0;
}
