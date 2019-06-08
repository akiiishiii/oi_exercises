// 2955.cpp
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> next;
    std::string s;
    int n, T = 0;
    while (std::cin >> n) {
        if (!n)
            break;
        std::cout << "Test case #" << ++T << '\n';
        std::cin >> s;
        s = ' ' + s;
        next.resize(n + 1);
        for (int i = 2, j = 0; i <= n; i++) {
            while (j > 0 && s[i] != s[j + 1])
                j = next[j];
            if (s[i] == s[j + 1])
                j++;
            next[i] = j;
        }
        for (int i = 2; i <= n; i++)
            if (!(i % (i - next[i])) && (i / (i - next[i]) != 1))
                std::cout << i << ' ' <<  i / (i - next[i]) << '\n';
        next.clear();
        std::cout << '\n';
    }
    return 0;
}