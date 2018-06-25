// 1066.cpp
#include <iostream>
#include <stack>

int main(int argc, const char * argv[]) {
	int n;
	std::stack<int> s;
	std::cin >> n;
	for (int i = 0, j; i < n; i++) {
		std::cin >> j;
		s.push(j);
	}
	while (!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << std::endl;
	return 0;
}
