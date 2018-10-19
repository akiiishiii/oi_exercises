// 2956.cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

void output(std::vector<int> &vn, int n);

int main(int argc, char const *argv[]) {
    int size = 40 << 20;
    __asm__("movq %0,%%rsp\n" ::"r"((char *)malloc(size) + size));
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> next;
    std::string s;
    while (std::cin >> s) {
        s = ' ' + s;
        next.resize(s.length());
        for (int i = 2, j = 0; i < s.length(); i++) {
            while (j > 0 && s[i] != s[j + 1])
                j = next[j];
            if (s[i] == s[j + 1])
                j++;
            next[i] = j;
        }
        ::output(next, s.length() - 1);
        std::cout << s.length() - 1 << '\n';
        next.clear();
    }
    exit(0);
    return 0;
}

void output(std::vector<int> &vn, int n) {
    if (n)
        ::output(vn, vn[n]);
    if (vn[n])
        std::cout << vn[n] << ' ';
}