// 2321.cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string dfs(std::string t);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::string a, b, ansa, ansb;
        std::cin >> a;
        a = "0" + a + "1";
        ansa = dfs(a);
        std::cin >> b;
        b = "0" + b + "1";
        ansb = dfs(b);
        if (ansa == ansb)
            std::cout << "same" << '\n';
        else
            std::cout << "different" << '\n';
    }
    return 0;
}

std::string dfs(std::string t) {
    if (t == "01")
        return t;
    int len = (int)t.size();
    std::string root = t.substr(1, len - 2);
    int cnt = 0;
    int start = 0;
    std::vector<std::string> s;
    for (int i = 0; i < len - 2; i++) {
        cnt += (root[i] == '0') ? 1 : -1;
        if (cnt == 0) {
            s.push_back(dfs(root.substr(start, i - start + 1)));
            start = i + 1;
        }
    }
    std::string ans = "0";
    sort(s.begin(), s.end());
    for (int j = 0; j < s.size(); j++) {
        ans += s[j];
    }
    return ans + "1";
}