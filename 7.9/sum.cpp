// sum.cpp
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("sum.in");
std::ofstream out("sum.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

inline long long fact(long long n);
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    long long n, m;
    in >> n >> m;
    long long fm = fact(n + m - 1), fz = 0, fz1 = 1;
    for (int i = m + 1; i <= m + n; i++)
    	fz1 *= i;
    for (int i = 1; i <= n + 1; i++) {
    	fz += fz1;
    	fz1 = fz1 * i / (m + i);
	}
	fz1 = gcd(fz, fm);
	std::cout << (fz / fz1) << '\n' << (fm / fz1) << '\n';
    return 0;
}

inline long long fact(long long n) {
	long long ret = 1;
	for (int i = 2; i <= n; i++)
		ret *= i;
	return ret;
}
