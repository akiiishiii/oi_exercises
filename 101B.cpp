#include <iostream>

int main(int argc, const char * argv[]) {
	int n, sum, temp;
	std::cin >> n;
	temp = n;
	while (temp) {
		sum += temp % 10;
		temp /= 10;
	}
	std::cout << (n % sum ? "No\n" : "Yes\n");
	return 0;
}
