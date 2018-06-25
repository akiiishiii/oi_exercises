// 1030.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    if (n < 100)
        std::cout << "10\n";
    else if (n < 110)
        std::cout << "30\n";
    else if (n < 120)
        std::cout << "50\n";
    else if (n < 130)
        std::cout << "70\n";
    else
        std::cout << "80\n";
    return 0;
}
