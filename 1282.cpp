// 1282.cpp
#include <iostream>
#include <string>
#include <algorithm>

std::__cxx11::basic_string<char> cc;
int m;
void dfs(int cur, int num);

int main(int argc, const char * argv[]) {

    std::cin >> cc >> m;
    std::sort(cc.begin(), cc.end());

    return 0;
}

void dfs(int cur, int num) {
    if (cur == cc.length() || num == m + 1)
        return;
    if ()
}