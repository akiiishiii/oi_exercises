// 1351.cpp
#include <iostream>
#include <string>

std::string s;
unsigned long long f[1000010], p[1000010];
int n, q;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> s >> q;
    s = ' ' + s;
    p[0] = 1;
    for (int i = 1; i < s.length(); i++) {
        f[i] = f[i - 1] * 131 + (s[i] - 'a' + 1);
        p[i] = p[i - 1] * 131;
    }
    for (int i = 1, l1, r1, l2, r2; i <= q; i++) {
        std::cin >> l1 >> r1 >> l2 >> r2;
        std::cout << ((f[r1] - f[l1 - 1] * p[r1 - l1 + 1] ==
                       f[r2] - f[l2 - 1] * p[r2 - l2 + 1])
                          ? "Yes\n"
                          : "No\n");
    }
    return 0;
}
