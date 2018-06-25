// 1039.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	char c;
	long long tot = 0;
	while ((c = std::cin.get()) != '#')
		if (c == 'a' ||  c == 'A')
			tot++;
	std::cout << tot << std::endl;
	return 0;
}
