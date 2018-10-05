// restore.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("restore.in");
std::ofstream out("restore.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

inline int getnum(std::string const sa, std::string const sb, int i);
inline bool comp(std::string const sa, std::string const sb);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n;
    std::string a, b, c;
    //std::string *ans = new std::string;
    in >> n >> a >> b >> c;
    if (comp(a, b)) {
        std::reverse(c.begin(), c.end());
        out << c << '\n';
    } else if (comp(b, c)) {
        std::reverse(a.begin(), a.end());
        out << a << '\n';
    } else {
        std::reverse(b.begin(), b.end());
        out << b << '\n';
    }
    return 0;
}

inline int getnum(std::string const sa, std::string const sb, int i) {
    int k = sa[i] - sb[i];
    if (k > 6)
        return k - 26;
    else if (k < -6)
        return k + 26;
    else
        return k;
}

inline bool comp(std::string const sa, std::string const sb) {
    int k = getnum(sa, sb, 0);
    for (int i = 1; i < sa.length(); i++)
        if (getnum(sa, sb, i) != k)
            return false;
    return true;
}