// 1083.cpp
#include <iostream>
#include <vector>
#include <string>

const char alpha[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

int main(int argc, const char * argv[]) {
    long long m, temp;
    int n;
    bool minus = false;
    std::vector<int> num;
    std::cin >> m >> n;
    if (m < 0) {
        minus = true;
        temp = -m;
    } else
        temp = m;
    while (temp) {
        num.insert(num.begin(), temp % n);
        temp /= n;
    }
    std::cout << "(" << m << ")10=(";
    if (minus)
        std::cout << '-';
    for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++)
        if (*it < 10)
            std::cout << *it;
        else
            std::cout << alpha[*it - 10];
    std::cout << ")" << n << std::endl;
    return 0;
}