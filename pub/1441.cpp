// 1441.cpp
#include <iostream>

int prt[5005];

void initializer(int x);
void merge(int a, int b);
int search(int a);

int main(int argc, char const *argv[]) {
    int n, m, p;
    std::cin >> n >> m >> p;
    initializer(n);
    for (int i = 0, mi, mj; i < m; i++) {
        std::cin >> mi >> mj;
        merge(mi, mj);
    }
    for (int i = 0, pi, pj; i < p; i++) {
        std::cin >> pi >> pj;
        std::cout << (search(pi) == search(pj) ? "Yes\n" : "No\n");
    }
    return 0;
}

void initializer(int x) {
    for (int i = 1; i <= x; i++)
        prt[i] = i;
}

void merge(int a, int b) {
    int fa = search(a), fb = search(b);
    if (fa != fb)
        prt[fa] = fb;
}

int search(int a) {
    if (prt[a] == a)
        return a;
    prt[a] = search(prt[a]);
    return prt[a];
}