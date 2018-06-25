// 1037.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int n, num, max, min;
	std::cin >> n >> num;
	max = min = num;
	for (int i = 1; i < n; i++) {
		std::cin >> num;
		max = max < num ? num : max;
		min = min > num ? num : min;
	}
	std::cout << max - min << std::endl;
	return 0;
}
