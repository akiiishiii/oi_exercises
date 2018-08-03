// 1314.cpp
#include <iostream>

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char c, s[10005], *top = s;
    int n;
    bool flag = true;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        top = s;
        while ((c = std::cin.get()) != '\n' || flag) {
            switch (c) {
                case '$':
                    flag = false;
                    if (top != s)
                        top--;
                    break;
                case '#':
                    flag = false;
                    top = s;
                    break;
                case '\n':
                    break;
                default:
                    flag = false;
                    *top = c;
                    top++;
                    break;
            }
        }
        for (char *pt = s; pt != top; pt++)
            std::cout << *pt;
        std::cout << '\n';
    }
    return 0;
}