// 3676.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int *p = new int;
    std::cin >> *p;
    std::cout << *p << '\n';
    delete p;
    std::cout << *p << '\n';
    return 0;
}