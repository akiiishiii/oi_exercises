// 1068.cpp
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    int n, dot = 0;
    std::vector<int> a, b;
    std::cin >> n;
    a.resize(n);
    b.resize(n);
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cin >> *it;
    for (std::vector<int>::iterator it = b.begin(); it != b.end(); it++)
        std::cin >> *it;
    for (int i = 0; i < n; i++)
        dot += a.at(i) * b.at(i);
    std::cout << dot << std::endl;
    return 0;
}
