#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

int random(int n) {
    return (long long)rand() * rand() % n;
}

void rev(std::string s) {
    std::reverse(s.begin(), s.end());
    std::cout << s << '\n';
}

void add(std::string s, int k) {
    for (int i = 0; i < s.length(); i++)
        s[i] += s[i] + k > 'z' ? k - 26 : k;
    std::cout << s << '\n';
}

void minus(std::string s, int k) {
    for (int i = 0; i < s.length(); i++)
        s[i] += s[i] - k < 'a' ? 26 - k : -k;
    std::cout << s << '\n';
}

int main() {
    freopen("restore.ans", "w", stdout);
    srand((unsigned)time(0));
    std::string s;
    int len = random(10000) + 1;
    s.resize(len);
    for (int i = 0; i < len; i++)
        s[i] = char('a' + random(26));
    std::cout << s << '\n';
    freopen("restore.in", "w", stdout);
    int k = random(6) + 1;
    switch(random(6) + 1) {
        case 1:
            add(s, k);
            rev(s);
            minus(s, k);
            break;
        case 2:
            minus(s, k);
            add(s, k);
            rev(s);
            break;
        case 3:
            rev(s);
            add(s, k);
            minus(s, k);
            break;
        case 4:
            rev(s);
            minus(s, k);
            add(s, k);
            break;
        case 5:
            add(s, k);
            minus(s, k);
            rev(s);
            break;
        case 6:
            minus(s, k);
            rev(s);
            add(s, k);
            break;
        default:
            break;
    }
    return 0;
}