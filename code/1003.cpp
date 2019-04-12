// 1003.cpp
#include <iostream>
#include <string>

int f[3005][3005];
std::string a, b;

int main(int argc, const char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < b.length(); j++)
            if (a[i] == b[j])
                f[i + 1][j + 1] =
                    std::max(std::max(f[i][j + 1], f[i + 1][j]), f[i][j] + 1);
            else
                f[i + 1][j + 1] = std::max(f[i + 1][j], f[i][j + 1]);
    std::cout << f[a.length()][b.length()] << std::endl;
    return 0;
}