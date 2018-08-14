// 1507.cpp
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>

template <typename T>
inline T max(const T &a, const T &b) { return a > b ? a : b; }

int f[5001][5001];

int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string a, b;
    int n;
    memset(f, 0, sizeof(f));
    std::cin >> n >> a;
    b = a;
    std::reverse(b.begin(), b.end());
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < b.length(); j++)
            if (a[i] == b[j])
                f[i + 1][j + 1] = max(max(f[i][j + 1], f[i + 1][j]), f[i][j] + 1);
            else
                f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]);
    std::cout << a.length() - f[a.length()][b.length()] << std::endl;
    return 0;
}