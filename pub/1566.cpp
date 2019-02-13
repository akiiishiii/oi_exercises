// 1566.cpp
#include <iostream>
#include <algorithm>

int prt[30005], s[30005];

void initializer(int x);
void merge(int a, int b);
int search(int a);

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    initializer(n);
    for (int i = 0, mi, mj; i < m; i++) {
        std::cin >> mi >> mj;
        merge(mi, mj);
    }
    std::cout << *std::max_element(s + 1, s + n + 1) << '\n';
    return 0;
}

void initializer(int x) {
    for (int i = 1; i <= x; i++) {
        s[i] = 1;
        prt[i] = i;
    }
}

void merge(int a, int b) {
    int fa = search(a), fb = search(b);
    if (fa != fb) {
        prt[fa] = fb;
        s[fb] += s[fa];
    }
}

int search(int a) {
    if (prt[a] == a)
        return a;
    prt[a] = search(prt[a]);
    return prt[a];
}