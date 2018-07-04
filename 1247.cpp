// 1247.cpp
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <iomanip>

std::string st;
std::stack<double> s;

void getn();
void calc(char c);

int main(int argc, const char * argv[]) {
    std::cin >> st;
    calc(st.front());
    std::cout << std::fixed << std::setprecision(6) << s.top() << std::endl;
    return 0;
}

void getn() {
    if (st.front() == '+' || st.front() == '-' || st.front() == '*'|| st.front() == '/')
        calc(st.front());
    else if (st.front() >= '0' && st.front() <= '9') {
        for (std::string::iterator it = st.begin(); it != st.end(); it++)
            if ((*it < '0' || *it > '9') && *it != '.') {
                s.push(stod(st.substr(0, it - st.begin())));
                st.erase(st.begin(), it);
            }
    } else {
        st.erase(st.begin());
        getn();
    }
}

void calc(char c) {
    st.erase(st.begin());
    getn();
    getn();
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    switch (c) {
        case '+':
            s.push(a + b);
            break;
        case '-':
            s.push(a - b);
            break;
        case '*':
            s.push(a * b);
            break;
        case '/':
            s.push(a / b);
            break;
        default:
            break;
    }
}