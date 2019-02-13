// 1380.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

int f[2001][2001];

int main(int argc, char const *argv[]) {
    std::string a, b;
    memset(f, 0, sizeof(f));
    std::cin >> a >> b;
    for (int i = 1; i <= a.length(); i++)
        f[i][0] = i;
    for (int j = 1; j <= b.length(); j++)
        f[0][j] = j;
    for (int i = 1; i <= a.length(); i++)
        for (int j = 1; j <= b.length(); j++)
            f[i][j] = ((a[i - 1] == b[j - 1]) ? f[i - 1][j - 1] : (std::min(f[i - 1][j], std::min(f[i][j - 1], f[i - 1][j - 1])) + 1));
    std::cout << f[a.length()][b.length()] << '\n';
    return 0;
}
