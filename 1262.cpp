// 1262.cpp
#include <iostream>

void divide(int n);
int m, p[100], c[100];

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    divide(n);
    if (c[1] != 1)
            std::cout << p[1] << '^' << c[1];
        else
            std::cout << p[1];
    for (int i = 2; i <= m; i++)
        if (c[i] != 1)
            std::cout << '*' << p[i] << '^' << c[i];
        else
            std::cout << '*' << p[i];
    std::cout << std::endl;
    return 0;
}

void divide(int n) {
    m = 0;
    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            p[++m] = i;
            c[m] = 0;
            while (!(n % i)) {
                n /= i;
                c[m]++;
            }
        }
    }
    if (n > 1) {
        p[++m] = n;
        c[m] = 1;
    }
    return;
}