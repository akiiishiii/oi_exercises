// 1477.cpp
#include <iostream>

int A[2][2] = {{0, 0}, {1, 0}}, I[2][2] = {{1, 0}, {0, 1}};

void multiply(int a[2][2], int b[2][2]);

int main(int argc, char const * argv[]) {
    int n;
    std::cin >> A[1][1] >> A[0][1] >> n;
    if (n >= 3) {
        n -= 2;
        while (n) {
            if (n & 1)
                multiply(I, A);
            multiply(A, A);
            n = n / 2;
        }
        std::cout << (I[0][1] % 7 + I[1][1] % 7) % 7;
    } else
        std::cout << 1;
    std::cout << '\n';
    return 0;
}

void multiply(int a[2][2], int b[2][2]) {
    int temp[2][2];
    temp[0][0] = ((a[0][0] % 7 * b[0][0] % 7) % 7 + (a[0][1] % 7 * b[1][0] % 7) % 7) % 7;
    temp[0][1] = ((a[0][0] % 7 * b[0][1] % 7) % 7 + (a[0][1] % 7 * b[1][1] % 7) % 7) % 7;
    temp[1][0] = ((a[1][0] % 7 * b[0][0] % 7) % 7 + (a[1][1] % 7 * b[1][0] % 7) % 7) % 7;
    temp[1][1] = ((a[1][0] % 7 * b[0][1] % 7) % 7 + (a[1][1] % 7 * b[1][1] % 7) % 7) % 7;
    a[0][0] = temp[0][0];
    a[0][1] = temp[0][1];
    a[1][0] = temp[1][0];
    a[1][1] = temp[1][1];
}