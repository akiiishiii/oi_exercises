#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
	double num, max, min, tot;
	std::cin >> num;
	tot = max = min = num;
	for (int i = 1; i < 10; i++) {
		std::cin >> num;
		max = max < num ? num : max;
		min = min > num ? num : min;
		tot += num;
	}
	std::cout << std::fixed << std::setprecision(2) << (tot - max - min) / 8 << std::endl;
	return 0;
}
