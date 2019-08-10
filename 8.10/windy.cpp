// windy.cpp
#include <fstream>
#include <iostream>
#include <string>

//#define debug

#ifndef debug

std::ifstream in("windy.in");
std::ofstream out("windy.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    long long a, b, ans = 0;
    in >> a >> b;
    for (long long i = a; i <= b; i++) {
        std::string s = std::to_string(i);
        bool is = true;
        for (int j = 1; j < s.length(); j++)
            if (std::abs(s[j] - s[j - 1]) < 2) {
                is = false;
                break;
            }
        if (is)
            ans++;
    }
    out << ans << '\n';
    return 0;
}