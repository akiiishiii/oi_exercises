// 1070.cpp
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    int n, tot = 0;
    std::vector<int> a;
    std::cin >> n;
    a.resize(n);
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cin >> *it;
    for (std::vector<int>::iterator it = a.begin() + 1; it != a.end() - 1; it++)
        if ((*it > *(it - 1) && *it > *(it + 1)) || (*it < *(it - 1) && *it < *(it + 1)))
            tot++;
    std::cout << tot + 1 << std::endl;
    return 0;
}
