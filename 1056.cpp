// 1056.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	double x, y, z;
	std::cin >> x >> y >> z;
	for (int i = 1; i <= 100 / x; i++)
		for (int j = 1; j <= 100 / y; j++)
			for (int k = 1; k <= 100 / z; k++)
				if (i * x + j * y + k * z == 100 && i + j + k == 100)
					std::cout << i << ' ' << j << ' ' << k << std::endl;
	return 0;
}
