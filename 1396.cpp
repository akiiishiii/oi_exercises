// 1396.cpp
#include <iostream>

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int res = 0;
    char c;
    while ((c = std::cin.get()) != '@') {
        if (c == '(')
            res++;
        else if (c == ')')
            res--;
    }
    std::cout << (res ? "NO" : "YES") << '\n';
    return 0;
}