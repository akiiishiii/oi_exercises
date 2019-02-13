// 1353.cpp
#include <iostream>
#include <cstring>
#include <string>

template <typename T>
inline T max(const T &a, const T &b) { return a > b ? a : b; }

int main(int argc, const char * argv[]) {
    std::string a, b;
    int f[205][205];
    memset(f, 0, sizeof(f));
    std::cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < b.length(); j++)
            if (a[i] == b[j])
                f[i + 1][j + 1] = max(max(f[i][j + 1], f[i + 1][j]), f[i][j] + 1);
            else
                f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]);
    std::cout << f[a.length()][b.length()] << std::endl;
    return 0;
}