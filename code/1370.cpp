// 1370.cpp
#include <iostream>
#include <stack>
#include <string>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::stack<char> s;
    std::string str;
    int ans = 0, tmp = 0;
    std::cin >> str;
    for (auto &&it : str)
        if (it == '(' || it == '[' || it == '{')
            s.push(it);
        else {
            if (s.size()) {
                if ((s.top() == '(' && it == ')') ||
                    (s.top() == '[' && it == ']') ||
                    (s.top() == '{' && it == '}'))
                    s.pop(), tmp += 2;
                else {
                    ans = std::max(ans, tmp), tmp = 0;
                    while (s.size())
                        s.pop();
                }
            } else
                ans = std::max(ans, tmp), tmp = 0;
        }
    ans = std::max(ans, tmp);
    std::cout << ans << '\n';
    return 0;
}