// math.cpp
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("math.in");
std::ofstream out("math.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    long long a, b;
    in >> a >> b;
    std::cout << a * b - a - b << '\n';
	return 0;
}
