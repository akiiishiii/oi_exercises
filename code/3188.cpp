// 3188.cpp
#include <iostream>
#include <stack>
#include <string>
#include <utility>

std::stack<char> op;
int f[100005][2], topf = 0;
int const Mod = 10007;

inline void setblank();
void calc();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int l;
    std::string s;
    std::cin >> l >> s;
    s = '(' + s + ')';
    for (std::string::iterator it = s.begin(); it != s.end(); it++)
        switch (*it) {
        case '+':
            while (op.top() != '(')
                calc();
            op.push(*it);
            if (*(it + 1) != '(')
                setblank();
            break;
        case '*':
            while (op.top() == '*')
                calc();
            op.push(*it);
            if (*(it + 1) != '(')
                setblank();
            break;
        case '(':
            op.push(*it);
            if (*(it + 1) != '(')
                setblank();
            break;
        case ')':
            while (op.top() != '(')
                calc();
            op.pop();
            break;
        default:
            break;
        }
    std::cout << f[topf][0] % Mod << '\n';
    return 0;
}

inline void setblank() {
    topf++;
    f[topf][0] = f[topf][1] = 1;
}

void calc() {
    int f0, f1;
    if (op.top() == '+') {
        f0 = (f[topf][0] * f[topf - 1][0]) % Mod;
        f1 = (f[topf][0] * f[topf - 1][1]) % Mod +
             (f[topf][1] * f[topf - 1][0]) % Mod +
             (f[topf][1] * f[topf - 1][1]) % Mod;
    } else {
        f0 = (f[topf][0] * f[topf - 1][1]) % Mod +
             (f[topf][1] * f[topf - 1][0]) % Mod +
             (f[topf][0] * f[topf - 1][0]) % Mod;
        f1 = (f[topf][1] * f[topf - 1][1]) % Mod;
    }
    op.pop();
    topf--;
    f[topf][0] = f0, f[topf][1] = f1;
}