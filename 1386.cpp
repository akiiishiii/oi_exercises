// 1386.cpp
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

int f[2001][2001];

int main(int argc, char const *argv[]) {
    memset(f, 0, sizeof(f));
    std::string a, b;
    int k;
    std::cin >> a >> b >> k;
    for(int i = 1; i <= a.length(); i++)
        f[i][0] = k + f[i - 1][0];
	for(int j = 1; j <= b.length(); j++)
        f[0][j] = k + f[0][j - 1];
    for (int i = 1, temp = 0; i <= a.length(); i++)
        for (int j = 1; j <= b.length(); j++) {
            f[i][j] = k + f[i-1][j];
			temp = f[i][j-1] + k;
            f[i][j] = std::min(temp, f[i][j]);
			temp = f[i - 1][j - 1] + abs(a[i - 1] - b[j - 1]);
            f[i][j] = std::min(temp, f[i][j]);
        }
    std::cout << f[a.length()][b.length()] << '\n';
    return 0;
}