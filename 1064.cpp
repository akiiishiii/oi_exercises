#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
	int n, m, tot = 0;
	std::vector<int> num;
	std::cin >> n;
	num.resize(n);
	for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++)
		std::cin >> *it;
	std::cin >> m;
	for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++)
		if (m == *it)
			tot++;
	std::cout << tot << std::endl;
	return 0;
}
