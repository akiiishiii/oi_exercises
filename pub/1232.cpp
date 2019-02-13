// 1232.cpp
#include <iostream>
#include <utility>
#include <vector>

int num = 0, n, tot = 0;

std::pair<char, int> color[4];

void dfs(int a, int b, int c);

int main(int argc, const char * argv[]) {
    int sum = 0, temp;
    char c;
    std::cin >> n;
    while (std::cin >> c && c != 'Q') {
        std::cin >> temp;
        sum = sum + temp;
        bool t = false;
        for (int i = 0; i < num; i++)
            if (std::get<0>(color[i]) == c) {
                std::get<1>(color[i]) += temp;
                t = true;
            }
        if (t == false) {
            std::get<0>(color[num]) = c;
            std::get<1>(color[num++]) = temp;
        }
    }
    int per = 1;
    for (int i = 1; i <= num; i++)
        per = per * i;
    if (n - sum - num + 1 <= 0)
        std::cout << 0 << std::endl;
    else {
        dfs(0, 0, 0);
        std::cout << tot * per << std::endl;
    }
    return 0;
}

void dfs(int a, int b, int c) {
    if (a == num && b == n) {
        tot++;
        return;
    }
    if (b > n)
        return;
    if (c != 1)
        dfs(a + 1, b + std::get<1>(color[a]), 1);
    dfs(a, b + 1, 0);
}