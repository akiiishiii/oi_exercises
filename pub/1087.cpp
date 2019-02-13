// 1087.cpp
#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    std::string s;
    std::cin >> s;
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        if (s[i] != s[j]) {
            std::cout << "NO\n";
            return 0;
        }
    std::cout << "YES\n";
    return 0;
}