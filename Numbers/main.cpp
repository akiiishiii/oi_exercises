// main.cpp

#include "numbers.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    Number n1, n2;
    char op;
    std::cin >> n1 >> op >> n2;
    switch (op) {
        case '+':
            std::cout << n1 + n2;
            break;
        case '-':
            std::cout << n1 - n2;
            break;
        case '*':
            std::cout << n1 * n2;
            break;
        case '/':
            std::cout << n1 / n2;
            break;
        case '%':
            std::cout << n1 % n2;
            break;
        default:
            break;
    }
    std::cout << '\n';
    return 0;
}
