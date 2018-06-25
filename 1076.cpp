#include <iostream>
#include <string>

std::string s[12] = {"LING ", "YI ", "ER ", "SAN ", "SI ", "WU ", "LIU ", "QI ", "BA ", "JIU ", "SHI ", "CUO LE"};

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    if (n >= 0 && n < 10)
        std::cout << s[n];
    else if (n <= 99)
        std::cout << s[n / 10] << s[10] << s[n % 10];
    else
        std::cout << s[11];
    std::cout << std::endl;
    return 0;
}