// 1031.cpp
#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    double a, b;
    char op;
    std::cin >> a >> b >> op;
    std::cout << std::fixed << std::setprecision(1);
    switch (op) {
        case '+':
            std::cout << a + b;
            break;
        case '-':
            std::cout << a - b;
            break;
        case '*':
            std::cout << a * b;
            break;
        case '/':
            if (!b)
                std::cout << "error";
            else
                std::cout << a / b;
            break;
    }
    std::cout << std::endl;
    return 0;
}
