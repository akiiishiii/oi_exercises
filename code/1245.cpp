// 1245.cpp
#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char const *argv[]) {
    std::string m;
    int n;
    std::cin >> n >> m;
    std::cout << '(' << m << ')' << n << "=(";
    int ans = 0;
    for (int i = 0; i < m.length(); i++) {
        char c = m[m.length() - 1 - i];
        ans += pow(n, i) * int(c > 65 ? c - 55 : c - 48);
    }
    std::cout << ans << ")10\n";
    return 0;
}
