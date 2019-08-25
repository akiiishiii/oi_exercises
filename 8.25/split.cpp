// split.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("split.in");
std::ofstream out("split.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long k, n, p;

long long power(long long a, long long b);
long long solve(long long a, long long b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> k >> n >> p;
    out << (solve(k, n - 2) + 1) % p << '\n';
    return 0;
}

long long power(long long a, long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1)
			ret = ret % p * a % p;
		a = a * a % p;
 		b = b / 2;
	}
	return ret;
}

long long solve(long long a, long long b) {
    if (b == 1)
        return a;
    long long tmp = solve(a, b / 2), t = power(a, b / 2);
    long long ret = (tmp * t + tmp) % p;
    if (b & 1)
        ret = (ret + power(a, b)) % p;
    return ret;
}
