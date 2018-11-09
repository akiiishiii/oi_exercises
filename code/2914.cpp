// 2914.cpp
#include <iostream>
#include <cstring>

void read(int a[]);
void print(int a[]);
int compare(int a[], int b[]);
void minus(int a[], int b[]);
void numcpy(int p[], int q[], int det);
void divide(int a[], int b[], int c[]);

int main(int argc, char const *argv[]) {
    int m[20005], n[20005], ans[20005];
    read(m);
    read(n);
    divide(m, n, ans);
    print(ans);
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

void numcpy(int a[], int b[], int det) {
    for (int i = 1; i <= a[0]; i++)
        b[i + det - 1] = a[i];
    b[0] = a[0] + det - 1;
}

void divide(int a[], int b[], int c[]) {
    int tmp[20005];
    c[0] = a[0] - b[0] + 1;
    for (int i = c[0]; i > 0; i--) {
        memset(tmp, 0, sizeof(tmp));
        numcpy(b, tmp, i);
        while (compare(a, tmp) >= 0) {
            c[i]++;
            minus(a, tmp);
        }
    }
    while (c[0] > 0 && c[c[0]] == 0)
        c[0]--;
    return;
}