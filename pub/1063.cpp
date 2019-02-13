// 1063.cpp
#include <iostream>
#include <queue>

int main(int argc, const char * argv[]) {
    int n, f = 0;
    std::queue<int> c;
    c.push(0);
    c.push(0);
    c.push(0);
    c.push(1);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        f += c.front();
        c.pop();
        c.push(f);
    }
    while (!c.empty()) {
        f += c.front();
        c.pop();
    }
    std::cout << f << std::endl;
    return 0;
}
