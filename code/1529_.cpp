// 1529_.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::cout << (n >= 100 ? "UNIQUE\n" : "AMBIGUOUS\n");
    return 0;
}