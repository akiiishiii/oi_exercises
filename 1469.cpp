// 1469.cpp
#include <iostream>

int prt[505], n;

void s(int root);

int main(int argc, char const * argv[]) {
    int root = 0;
    std::cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        std::cin >> x >> y;
        prt[x] = y;
    }
    for (int i = 1; i <= n; i++)
        if (!prt[i]) {
            root = i;
            break;
        }
    s(root);
    return 0;
}

void s(int root) {
    for (int i = 1; i <= n; i++)
        if (prt[i] == root)
            s(i);
    std::cout << root << ' ';
    return;
}
