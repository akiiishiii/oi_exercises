// 1349_.cpp
#include <iostream>

inline int calc(char c);
inline char anti_calc(int t);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    return 0;
}

inline int calc(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 36;
    else if (c >= '0' && c <= '9')
        return c - '0';
    else
        return 0;
}

inline char anti_calc(int t) {
    if (t >= 10 && t <= 35)
        return t - 10 + 'A';
    else if (t >= 36 && t <= 61)
        return t - 36 + 'a';
    else if (t >= 0 && t <= 9)
        return t + '0';
    else
        return ' ';
}