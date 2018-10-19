// 3589.cpp
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, ans;
    std::vector<int> next, f;
    std::string s1, s2;
    std::cin >> T;
    while (T--) {
        ans = 0;
        std::cin >> s1 >> s2;
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        next.resize(s1.length());
        f.resize(s2.length());
        for (int i = 2, j = 0; i < s1.length(); i++) {
            while (j > 0 && s1[i] != s1[j + 1])
                j = next[j];
            if (s1[i] == s1[j + 1])
                j++;
            next[i] = j;
        }
        for (int i = 1, j = 0; i < s2.length(); i++) {
            while (j > 0 && (j == s1.length() - 1 || s2[i] != s1[j + 1]))
                j = next[j];
            if (s2[i] == s1[j + 1])
                j++;
            f[i] = j;
            if(f[i] == s1.length() - 1)
                ans++;
        }
        std::cout << ans << '\n';
        next.clear();
        f.clear();
    }
    return 0;
}
