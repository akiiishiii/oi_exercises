// 1314_.cpp
#include <iostream>
#include <stack>
#include <string>

int main(int argc, const char * argv[]) {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::stack<char> sc;
		std::string ans;
		char c;
		while (std::cin >> c && c != '\n') {
			sc.push(c);
			if (sc.top() == '$') {
				sc.pop();
				sc.pop();
			} else if (sc.top() == '#')
				while (!sc.empty())
					sc.pop();
		}
		while (!sc.empty()) {
			ans.push_back(sc.top());
			sc.pop();
		}
		for (int i = ans.size() - 1; i >= 0; i--)
			std::cout << ans[i];
		std::cout << std::endl;
	}
	return 0;
}
