// 1084.cpp
#include <iostream>
#include <cmath>
#include <string>

int main(int argc, const char * argv[]) {
    int n, res = 0;
    std::string m, temp;
    std::cin >> n >> m;
    temp = m;
    for (int i = 0; !temp.empty(); i++) {
        if (temp.back() >= 'A' && temp.back() <= 'F')
            res += int(temp.back() - 'A' + 10) * pow(n, i);
        else
            res += int(temp.back() - '0') * pow(n, i);
        temp.erase(temp.end() - 1);
    }
    std::cout << "(" << m << ")" << n << "=(" << res << ")10" << std::endl;
    return 0;
}