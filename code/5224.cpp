// 5224.cpp
#include <iostream>
#include <string>
#include <cstring>

int p[110010];

int manacher(std::string t);

int main(int argc, char const *argv[]) {
    std::string s;
    while (std::cin >> s)
        std::cout << manacher(s) << '\n';
    return 0;
}

int manacher(std::string t) {
    std::string s;
    s.resize(t.length() * 3);
    memset(p, 0, sizeof p);
    int ans = -1, len = 0;
    s[len] = '$';
    for (int i = 0; i < t.length(); i++) {
        s[++len] = '#';
        s[++len] = t[i];
    }
    s[++len] = '#';
    s[++len] = '\0';
    for (int i = 1, k = 0, mx = 0; i < len; i++) {
        if (mx > i)
            p[i] = std::min(p[k * 2 - i], mx - i);
        else
            p[i] = 1;
        while (s[i + p[i]] == s[i - p[i]])
            p[i]++;
        if (p[i] + i > mx) {
            mx = p[i] + i;
            k = i;
        }
        ans = std::max(ans, p[i] - 1);
    }
    return ans;
}