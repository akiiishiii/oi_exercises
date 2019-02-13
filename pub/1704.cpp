// 1704.cpp
#include <iostream>
#include <cstring>
#include <string>

int ans[500] = {1, 1};

void read(int &x);
void write(int x);
void write(int a[]);
void multiply(int a[], int k);
void divide(int a[], int b);

int main(int argc, char const *argv[]) {
    int m, n;
    read(m);
    read(n);
    for (int i = 1; i <= m; i++) {
        multiply(ans, n - i + 1);
        divide(ans, i);
    }
    write(ans);
    return 0;
}

void read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        std::cout.put(x / y + 48);
        x %= y;
    }
}

void write(int a[]) {
    if (a[0])
        for (int i = a[0]; i >= 1; i--)
            write(a[i]);
    else
        std::cout.put('0');
    std::cout.put('\n');
}

void multiply(int a[], int k) {
    for (int i = 1; i <= a[0]; i++)
        a[i] *= k;
    for (int i = 1; i <= a[0]; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    while (a[a[0] + 1] > 0) {
        a[0]++;
        a[a[0] + 1] += a[a[0]] / 10;
        a[a[0]] %= 10;
    }
}

void divide(int a[], int b) {
    for (int i = a[0], d = 0; i >= 1; i--) {
        d = d * 10 + a[i];
        a[i] = d / b;
        d %= b;
    }
    while (a[0] > 0 && !a[a[0]])
        a[0]--;
}