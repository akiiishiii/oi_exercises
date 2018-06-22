#include <iostream>

int main(int argc, const char * argv[]) {
	int n, k;
	std::cin >> n >> k;
	int money = n, years = 1;
	double price = 200;
	
	while (money < price && years <= 25) {
		money += n;
		price *= (100 + k) / 100.0;
		years++;
	}
	if (years <= 20)
		std::cout << years << std::endl;
	else
		std::cout << "Impossible\n";
}
