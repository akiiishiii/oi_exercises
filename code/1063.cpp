// 1063.cpp
#include <iostream>

int catalan[19] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700,};

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::cout << catalan[n] << '\n';
    return 0;
}
