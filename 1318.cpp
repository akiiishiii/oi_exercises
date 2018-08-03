// 1318.cpp
#include <iostream>
#include <stack>
#include <string>

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, temp = 0;
    std::string s;
    std::stack<int> ss;
    std::cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B')
            temp++;
        else if (s[i] == 'C')
            temp--;
        if (temp > 5 || temp < 0) {
            std::cout << "No\n";
            return 0;
        }
    }
    std::cout << "Yes\n";
    temp = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            std::cout << temp++ << '\n';
        else if (s[i] == 'B')
            ss.push(temp++);
        else if (s[i] == 'C') {
            std::cout << ss.top() << '\n';
            ss.pop();
        }
    }
    return 0;
}