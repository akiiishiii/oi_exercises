// 1077.cpp
#include <iostream>
#include <string>
#include <iomanip>

bool check(std::string &s);
int getalpha(std::string &s, char c);

int main(int argc, const char * argv[]) {
    int n, tot1 = 0, tot2 = 0, totl = 0;
    char c;
    std::string s;
    std::cin >> n >> c;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        if (check(s))
            tot1++;
        tot2 += getalpha(s, c);
        totl += s.length();
    }
    std::cout << tot1 << std::endl << std::fixed << std::setprecision(2) << tot2 * 100.0 / totl << "%\n";
    return 0;
}

bool check(std::string &s) {
    bool result = false;
    if (s.substr(0, 3) == "con")
        result = true;
    return result;
}

int getalpha(std::string &s, char c) {
    int result = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == c)
            result++;
    return result;
}