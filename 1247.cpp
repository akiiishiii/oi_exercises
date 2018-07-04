// 1247.cpp
#include <iostream>
#include <string>
#include <iomanip>

double calc();

int main(int argc, const char * argv[]) {
    std::cout << std::fixed << std::setprecision(6) << calc() << std::endl;
    return 0;
}

double calc() {
    std::string s;
    std::cin >> s;
    switch (s.front()) {
        case'+':
            return calc() + calc();
        case'-':
            return s.length() > 1 ? stod(s) : calc() - calc();
        case'*':
            return calc() * calc();
        case'/':
            return calc() / calc();
        default:
            return stod(s);
    }
}