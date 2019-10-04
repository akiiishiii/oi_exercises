// string.cpp
#include <fstream>
#include <iostream>
#include <string>

//#define debug

#ifndef debug

std::ifstream in("string.in");
std::ofstream out("string.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int T;
    std::string s;
    in >> T;
    while (T--) {
        in >> s;
        if (s.length() <= 8)
            out << s << '\n';
        else
            out << "hello\n";
    }
    return 0;
}