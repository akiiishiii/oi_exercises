// substring.cpp
#include <fstream>
#include <iostream>
#include <string>

//#define debug

#ifndef debug

std::ifstream in("substring.in");
std::ofstream out("substring.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int f[300005], tmp = 0;
long long ans = 0;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    std::string a, b;
    in >> a >> b;
    int la = a.length(), lb = b.length();
    a = ' ' + a, b = ' ' + b;
    for (int i = 1; i <= la; i++) {
    	f[0] = i;
    	for (int j = lb; j >= 1; j--)
    		if (a[i] == b[j]) {
    			f[j] = f[j - 1];
    			if (f[j] && j == lb) {
    				ans += 1ll * (f[j] - tmp) * (la - i + 1);
    				tmp = f[j];
    			}
			}
	}
	out << ans << '\n';
    return 0;
}
