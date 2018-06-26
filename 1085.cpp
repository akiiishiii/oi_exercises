// 1085.cpp
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

const char alpha[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

int main (int argc, const char * argv[]) {
    std::string s;
    int m, n, temp = 0;
    std::vector<int> num;
    std::cin >> n >> s >> m;
    for (int i = 0; !s.empty(); i++) {
        if (s.back() >= 'A' && s.back() <= 'F')
            temp += int(s.back() - 'A' + 10) * pow(n, i);
        else
            temp += int(s.back() - '0') * pow(n, i);
        s.erase(s.end() - 1);
    }
    while (temp) {
        num.insert(num.begin(), temp % m);
        temp /= m;
    }
    for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++)
        if (*it < 10)
            std::cout << *it;
        else
            std::cout << alpha[*it - 10];
    return 0;
}