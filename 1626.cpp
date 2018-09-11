// 1626.cpp
#include <iostream>
#include <cstring>

int mat[101][101];
int cnt = 0, n;

int read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    while (!read(n)) {
        memset(mat, 0, sizeof(mat));
    }
    return 0;
}

int read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
    return x;
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