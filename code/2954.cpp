// 2954.cpp
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> next;
    std::string s;
    while (true) {
        std::cin >> s;
        if (s == ".")
            break;
        s = ' ' + s;
        next.resize(s.length());
        for (int i = 2, j = 0; i < s.length(); i++) {
            while (j > 0 && s[i] != s[j + 1])
                j = next[j];
            if (s[i] == s[j + 1])
                j++;
            next[i] = j;
        }
        if (!((s.length() - 1) % (s.length() - next[s.length() - 1] - 1)))
            std::cout << (s.length() - 1) / (s.length() - next[s.length() - 1] - 1) << '\n';
        else
            std::cout << "1\n";
        next.clear();
    }
    return 0;
}
