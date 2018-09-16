// date.cpp
#include <iostream>
#include <fstream>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("date.in");
std::ofstream out("date.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int d1, d2, ans = 0;
    in >> d2 >> d1;
    for (int month = 1; month <= 12; month++)
        for (int day = 1; day <= Days[month]; day++) {
            int year = (day % 10) * 1000 + (day / 10) * 100 + (month % 10) * 10 + (month / 10);
            int d = year * 10000 + month * 100 + day;
            if (d < d2 || d > d1)
                continue;
            ans++;
        }
    out << ans << '\n';
    return 0;
}