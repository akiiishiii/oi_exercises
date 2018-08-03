// 1409.cpp
#include <iostream>

int main(int argc, char const * argv[]) {
    int m, n, x, y, prt[1005] = {0}, num[1005] = {0}, maxx = 0, root = 0;
    std::cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> x >> y;
        prt[y] = x;
        num[x]++;
    }
    for (int i = 1; i <= m; i++) {
        if (!prt[i])
            root = i;
        maxx = num[i] > num[maxx] ? i : maxx;
    }
    std::cout << root << '\n' << maxx << '\n';
    for (int i = 1; i <= m; i++)
        if (prt[i] == maxx)
            std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}
