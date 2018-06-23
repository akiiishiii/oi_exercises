#include <iostream>

int main(int argc, const char * argv[]) {
	int n, pedal[3], tot[3] = {0};
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> pedal[j];
			tot[j] += pedal[j];
		}
	}
	std::cout << tot[0] << ' ' << tot[1] << ' ' << tot[2] << ' ' << tot[0] + tot[1] + tot[2] << std::endl;
	return 0;
}
