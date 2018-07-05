// 1189.cpp
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    int n;
    std::vector<int> a = {2};
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
            *it *= 2;
        for (std::vector<int>::iterator it = a.begin(); it != a.end() - 1; it++)
            if (*it >= 10) {
                *(it + 1) += *it / 10;
                *it %= 10;
            }
        if (*(a.end() - 1) > 10) {
                a.push_back(*(a.end() - 1) / 10);
                *(a.end() - 2) %= 10;
            }
    }
    a.front() -= 2;
    for (std::vector<int>::iterator it = a.end() - 1; it != a.begin() - 1; it--)
        std::cout << *it;
    std::cout << std::endl;
    return 0;
}