// 1248.cpp
#include <iostream>
#include <string>
#include <algorithm>

int a[10] = {0}, n, num = 0;
bool b[10] = {false};
std::string s;

void dfs(int sta);

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    n = s.length();
    std::sort(s.begin(), s.end());
    dfs(1);
    return 0;
}

void dfs(int sta) {
    if (sta == n + 1) {
        std::cout << ++num << ':';
        for (int i = 1; i <= n; i++)
            std::cout << s[a[i] - 1];
        std::cout << std::endl;
    }
    else
        for (int i = 1; i <= n; i++)
            if (!b[i]) {
                a[sta] = i;
                b[i] = true;
                dfs(sta + 1);
                b[i] = false;
            }
}