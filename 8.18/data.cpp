// data.cpp
#include <cmath>
#include <iostream>
#include <fstream>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("data.in");
std::ofstream out("data.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n;
int a[100005], f[100005];
std::priority_queue<int> bigq;


int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> a[i];
    for (int i = 1; i <= n; i++) {
        f[i] = 0x3f3f3f3f;
        for (int k = i - 1; k >= 0; k--) {
            f[i] = std::min(f[i], f[k] + abs(a[k + 1] - (i - k - 1)));
        }
    }
    out << f[n] << '\n';
	return 0;
}

// f[i] = min{f[j]+|num[j+1]-(i-j-1)|}
