// 1314.cpp
#include <iostream>
#include <string>

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char s[10005], *top = s;
    int n;
    std::string st;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        top = s;
        std::cin >> st;
        for (std::string::iterator it = st.begin(); it != st.end(); it++)
            switch (*it) {
                case '$':
                    if (top != s)
                        top--;
                    break;
                case '#':
                    top = s;
                    break;
                 default:
                    *top = *it;
                    top++;
                    break;
            }
        for (char *pt = s; pt != top; pt++)
            std::cout << *pt;
        std::cout << '\n';
    }
    return 0;
}