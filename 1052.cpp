// 1052.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			std::cout.put('*');
		std::cout << std::endl;
	}
	return 0;
}
