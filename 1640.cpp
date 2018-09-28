// 1640.cpp
#include <iostream>
#include <cstring>
#include <string>

int anst;

void read(int a[]);
void print(int a[]);
int compare(int a[], int b[]);
//void plus(int a[], int b[]);
void minus(int a[], int b[]);
void multiply(int a[], int k);
void multiply(int a[], int b[]);
void divide(int a[], int b);
void gcd(int a[], int b[], int t);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a[3001], b[3001], pow2[3001] = {1, 1};
    read(a);
    read(b);
    gcd(a, b, 0);
    for (int i = 1; i <= anst; i++)
        multiply(pow2, 2);
    multiply(a, pow2);
    print(a);
    std::cout.put('\n');
    return 0;
}

void read(int a[]) {
    std::string s;
    std::cin >> s;
    a[0] = s.length();
    for (int i = 1; i <= a[0]; i++)
        a[i] = s[a[0] - i] - '0';
}

void print(int a[]) {
    if (!a[0]) {
        std::cout.put('0');
        return;
    }
    for (int i = a[0]; i >= 1; i--)
        std::cout << a[i];
}

int compare(int a[], int b[]) {
    if (a[0] > b[0])
        return 1;
    else if (a[0] < b[0])
        return -1;
    for (int i = a[0]; i >= 1; i--) {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return -1;
    }
    return 0;
}
/*
void plus(int a[], int b[]) {
    if (a[0] < b[0])
        a[0] = b[0];
    for (int i = 1; i <= a[0]; i++)
        a[i] = a[i] + b[i];
    for (int i = 1; i <= a[0]; i++) {
        a[i + 1] = a[i + 1] + a[i] / 10;
        a[i] = a[i] % 10;
    }
    if (a[a[0] + 1] > 0)
        a[0]++;
}
*/
void minus(int a[], int b[]) {
    int cmp = compare(a, b);
    if (!cmp) {
        a[0] = 0;
        return;
    }
    else if (cmp == -1) {
        std::cout << '-';
        a[0] = b[0];
        for (int i = 1; i <= a[0]; i++)
            std::swap(a[i], b[i]);
    }
    for (int i = 1; i <= a[0]; i++) {
        if (a[i] < b[i]) {
            a[i + 1]--;
            a[i] += 10;
        }
        a[i] = a[i] - b[i];
    }
    while (a[0] > 0 && !a[a[0]])
        a[0]--;
}

void multiply(int a[], int k) {
    for (int i = 1; i <= a[0]; i++)
        a[i] = a[i] * k;
    for (int i = 1; i <= a[0]; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    while (a[a[0] + 1] > 0) {
        a[0]++;
        a[a[0] + 1] += a[a[0]] / 10;
        a[a[0]] = a[a[0]] % 10;
    }
}

void multiply(int a[], int b[]) {
    int c[3001] = {0};
    for (int i = 1; i <= a[0]; i++)
        for (int j = 1; j <= b[0]; j++)
            c[i + j - 1] += a[i] * b[j];
    c[0] = a[0] + b[0];
    for (int i = 1; i <= c[0]; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c[0] > 0 && !c[c[0]])
        c[0]--;
    memcpy(a, c, sizeof(c));
}

void divide(int a[], int b) {
    int d = 0;
    for (int i = a[0]; i >= 1; i--) {
        d = d * 10 + a[i];
        a[i] = d / b;
        d = d % b;
    }
    while (a[0] > 0 && !a[a[0]])
        a[0]--;
}

void gcd(int a[], int b[], int t) {
    if (!compare(a, b)) {
        anst = t;
        return;
    } else if (compare(a, b) < 0) {
        gcd(b, a, t);
        return;
    }
    bool ta, tb;
    if (!(a[1] % 2)) {
        divide(a, 2);
        ta = true;
    } else
        ta = false;
    if (!(b[1] % 2)) {
        divide(b, 2);
        tb = true;
    } else
        tb = false;
    if (ta && tb)
        gcd(a, b, t + 1);
    else if (!(ta || tb)) {
        minus(a, b);
        gcd(a, b, t);
    } else
        gcd(a, b, t);
}