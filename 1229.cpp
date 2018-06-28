// 1229.cpp
#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::string s;
    int n;
    char ci;
    while ((ci = std::cin.get()) != '.')
        s.push_back(ci);
    s.push_back('.');
    std::cin >>  n;
    for (int i = 0; i < n; i++) {
        char c, a, b;
        std::cin >> c;
        if (c == 'D') {
            std::cin >> a;
            s.erase(std::search_n(s.begin(), s.end(), 1, a));
        } else if (c == 'l') {
            std::cin >> a >> b;
            for (std::string::iterator it = s.end() - 1; it >= s.begin(); it--) {
                if (*it == a)
                    s.insert(it, b);
            }
        } else if (c == 'R') {
            std::cin >> a >> b;
            for (std::string::iterator it = s.begin(); it != s.end(); it++) {
                if (*it == a)
                    *it = b;
            }
        }
    }
    std::cout << s << std::endl;
    return 0;
}