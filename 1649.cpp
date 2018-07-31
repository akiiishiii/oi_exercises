// 1649.cpp
#include <iostream>
#include <algorithm>
#include <vector>

struct act {
    int b, e;
    bool operator<(act const & a) const { return e < a.e; }
    friend std::istream & operator>>(std::istream & is, act & a);
};

int main(int argc, char const * argv[]) {
    int n;
    std::vector<act> a;
    std::cin >> n;
    std.resize(n);
    for (std::vector<act>::iterator it = a.begin(); it != a.end(); it++)
        std::cin >> *it;
    std::sort(a.begin(), a.end());
    for (std::vector<act>::iterator it = a.begin(); it != a.end(); it++) {

    }
    return 0;
}

std::istream & operator>>(std::istream & is, act & a) {
    is >> a.b >> a.e;
    return is;
}