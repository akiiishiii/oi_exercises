// 1237.cpp
#include <iostream>
#include <stack>

int main(int argc, const char * argv[]) {
    std::stack<char> s;
    char c;
    while ((c = std::cin.get()) != '!')
        s.push(c);
    std::cout << '!';
    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
    return 0;
}