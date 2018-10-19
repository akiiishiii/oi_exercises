// 1244.cpp
#include <iostream>
#include <stack>

std::stack<char> s;

int main(int argc, char const *argv[]) {
    int m, n;
    std::cin >> m >> n;
    std::cout << '(' << m << ")10=(";
    while (m) {
        int t = m % n;
        s.push((t >= 10) ? (55 + t) : (48 + t));
        m /= n;
    }
    while (s.size()) {
        std::cout << s.top();
        s.pop();
    }
    std::cout << ')' << n << '\n';
    return 0;
}
