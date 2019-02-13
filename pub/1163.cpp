// 1163.cpp
#include <iostream>
#include <vector>
#include <string>

std::vector<int> nums;
std::vector<char> ops;

int solve(std::string s);
void calc(char op);
int grade(char op);
int calc(int l, int r, std::string s);

int main(int argc, const char * argv[]) {
    std::string st;
    std::cin >> st;
    std::cout << solve(st) << std::endl << calc(0, st.length() - 1, st);
    return 0;
}

int solve(std::string s) {
	nums.clear();
	ops.clear();
	int val = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			val = val * 10 + s[i] - '0';
			if (s[i+1] >= '0' && s[i+1] <= '9')
                continue;
			nums.push_back(val);
			val = 0;
		}
		else if (s[i] == '(')
            ops.push_back(s[i]);
		else if (s[i] == ')') {
			while (*ops.rbegin() != '(') {
				calc(*ops.rbegin());
				ops.pop_back();
			}
			ops.pop_back();
		}
		else {
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

int calc(int l, int r, std::string s) {
	for (int i = r, j = 0; i >= l; i--) {
		if (s[i] == '(') j++;
		if (s[i] == ')') j--;
		if (j == 0 && s[i] == '+')
            return calc(l, i - 1, s) + calc(i + 1, r, s);
		if (j == 0 && s[i] == '-')
            return calc(l, i - 1, s) - calc(i + 1, r, s);
	}
	for (int i = r, j = 0; i >= l; i--) {
		if (s[i] == '(') j++;
		if (s[i] == ')') j--;
		if (j == 0 && s[i] == '*')
            return calc(l, i - 1, s) * calc(i + 1, r, s);
		if (j == 0 && s[i] == '/')
            return calc(l, i - 1, s) / calc(i + 1, r, s);
	}
	if (s[l] == '(' && s[r] == ')')
        return calc(l + 1, r - 1, s);
	int ans = 0;
	for (int i = l; i <= r; i++)
        ans = ans * 10 + s[i] - '0';
	return ans;
}