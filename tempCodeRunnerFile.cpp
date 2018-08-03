// 1314.cpp
#include <iostream>
#include <string>

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char s[10005], *top = s;
    int n;
    bool flag = true;
    std::string st;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        top = s;
        while (true) {
            std::cin >> st;
            for (std::string::iterator it = st.begin(); it != st.end(); it++)
                switch (*it) {
                    case '$':
                        flag = false;
                        if (top != s)
                            top--;
                        break;
                    case '#':
                        flag = false;
                        top = s;
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