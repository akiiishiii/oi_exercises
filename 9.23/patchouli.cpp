// patchouli.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

//#define debug

#ifndef debug

std::ifstream in("patchouli.in");
std::ofstream out("patchouli.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

std::string s;
int m, tmp = 0, len;
int snum[2005] = {0}, f[2005][26];

inline int chk(int a, int b) { return (tmp + f[b][snum[a]] + f[a][snum[b]] - f[a][snum[a]] - f[b][snum[b]]) % m; }

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	memset(f, 0, sizeof(f));
    in >> s;
    len = s.length();
    in >> m;
    for (int i = 1; i <= len; i++)
    	snum[i] = s[i - 1] - 'A';
    for (int i = len; i >= 1; i--)
    	for (int j = 0; j < 26; j++) {
        	if (i == len)
            	f[i][j] = j % m;
        	else
            	f[i][j] = (f[i + 1][j] * 26) % m;
    	}
    for (int i = 1; i <= len; i++)
    	tmp = (tmp * 26 + snum[i]) % m;
    if (!tmp) {
    	out << "0 0\n";
    	return 0;
    }
    for (int i = 1; i < len; i++)
    	for (int j = i + 1; j <= len; j++)
    		if (snum[i] != snum[j])
        		if (!chk(i, j)) {
        			out << i << ' ' << j << '\n';
        			return 0;
        		}
    out << "-1 -1";
	return 0;
}
