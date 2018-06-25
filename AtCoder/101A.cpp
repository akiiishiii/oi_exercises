// 101A.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int num = 0;
	char c;
	for (int i = 0; i < 4; i++) {
		c = std::cin.get();
		if (c == '+')
			num++;
		else if (c == '-')
			num--;
	}
	std::cout << num << std::endl;
	return 0;
}
