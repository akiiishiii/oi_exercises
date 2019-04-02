// 1401.cpp
#include <iostream>
#include <vector>

std::vector<int> nums;
std::vector<char> ops;

int grade(char op);
void calc(char op);
int solve(std::string s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin >> s;
    std::cout << solve(s) << '\n';
    return 0;
}

int grade(char op) {
    switch (op) {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
    return 0;
}

void calc(char op) {
    int y = *nums.rbegin();
    nums.pop_back();
    int x = *nums.rbegin();
    nums.pop_back();
    int z;
    switch (op) {
    case '+':
        z = x + y;
        break;
    case '-':
        z = x - y;
        break;
    case '*':
        z = x * y;
        break;
    case '/':
        z = x / y;
        break;
    }
    nums.push_back(z);
}

int solve(std::string s) {
    nums.clear();
    ops.clear();
    int val = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            val = val * 10 + s[i] - '0';
            if (s[i + 1] >= '0' && s[i + 1] <= '9')
                continue;
            nums.push_back(val);
            val = 0;
        } else if (s[i] == '(')
            ops.push_back(s[i]);
        else if (s[i] == ')') {
            while (*ops.rbegin() != '(') {
                calc(*ops.rbegin());
                ops.pop_back();
            }
            ops.pop_back();
        } else {
            while (ops.size() && grade(*ops.rbegin()) >= grade(s[i])) {
                calc(*ops.rbegin());
                ops.pop_back();
            }
            ops.push_back(s[i]);
        }
    }
    while (ops.size()) {
        calc(*ops.rbegin());
        ops.pop_back();
    }
    return *nums.begin();
}