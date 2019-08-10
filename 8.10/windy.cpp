// windy.cpp
#include <cstring>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("windy.in");
std::ofstream out("windy.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int a, b;
int f[15][15], c[15];

int calc(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    std::cin >> a >> b;
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 10; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
            }
        }
    }
    std::cout << calc(b + 1) - calc(a) << '\n';
    return 0;
}

int calc(int x) {
    memset(c, 0, sizeof(c));
    int len = 0, ans = 0;
    while (x) {
        c[++len] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= len - 1; i++)
        for (int j = 1; j <= 9; j++)
            ans += f[i][j];
    for (int i = 1; i < c[len]; i++)
        ans += f[len][i];
    for (int i = len - 1; i >= 1; i--) {
        for (int j = 0; j <= c[i] - 1; j++)
            if (abs(j - c[i + 1]) >= 2)
                ans += f[i][j];
        if (abs(c[i + 1] - c[i]) < 2)
            break;
    }
    return ans;
}