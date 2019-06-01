// 1217.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

struct minister {
    int a, b, p;
} a[1002];

int ans[40005], pro[40005], tmp[40005];

bool cmp(minister a, minister b) { return a.p < b.p; }

inline void multiply(int a[], int x) {
    for (int i = 1; i <= a[0]; i++)
        a[i] *= x;
    for (int i = 1; i <= a[0]; i++)
        a[i + 1] += a[i] / 10, a[i] %= 10;
    while (a[0] > 0 && a[a[0] + 1])
        a[0]++, a[a[0] + 1] = a[a[0]] / 10, a[a[0]] %= 10;
}

inline void divide(int a[], int b, int tmp[]) {
    int minister = 0;
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i <= a[0]; i++)
        tmp[i] = a[i];
    for (int i = tmp[0]; i >= 1; i--) {
        minister = minister * 10 + tmp[i];
        tmp[i] = minister / b;
        minister %= b;
    }
    while (tmp[0] && tmp[tmp[0]] == 0)
        tmp[0]--;
}

inline int compare(int a[], int b[]) {
    if (a[0] > b[0])
        return 1;
    if (a[0] < b[0])
        return -1;
    for (int i = a[0]; i >= 1; i--) {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}

inline void copy(int a[], int b[]);
void print(int a[]);

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n + 1; i++)
        std::cin >> a[i].a >> a[i].b, a[i].p = a[i].b * a[i].a;
    std::sort(a + 2, a + 2 + n, cmp);
    pro[1] = a[1].a;
    pro[0] = ans[0] = 1;
    while (pro[pro[0]] >= 10)
        pro[0]++, pro[pro[0]] = pro[pro[0] - 1] / 10, pro[pro[0] - 1] %= 10;
    ans[1] = 0;
    for (int i = 2; i <= n + 1; i++) {
        divide(pro, a[i].b, tmp);
        if (compare(tmp, ans) > 0)
            copy(ans, tmp);
        multiply(pro, a[i].a);
    }
    print(ans);
}

inline void multiply(int a[], int x) {
    for (int i = 1; i <= a[0]; i++)
        a[i] *= x;
    for (int i = 1; i <= a[0]; i++)
        a[i + 1] += a[i] / 10, a[i] %= 10;
    while (a[0] > 0 && a[a[0] + 1])
        a[0]++, a[a[0] + 1] = a[a[0]] / 10, a[a[0]] %= 10;
}

inline void divide(int a[], int b, int tmp[]) {
    int minister = 0;
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i <= a[0]; i++)
        tmp[i] = a[i];
    for (int i = tmp[0]; i >= 1; i--) {
        minister = minister * 10 + tmp[i];
        tmp[i] = minister / b;
        minister %= b;
    }
    while (tmp[0] && tmp[tmp[0]] == 0)
        tmp[0]--;
}

inline int compare(int a[], int b[]) {
    if (a[0] > b[0])
        return 1;
    if (a[0] < b[0])
        return -1;
    for (int i = a[0]; i >= 1; i--) {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}

inline void copy(int a[], int b[]) {
    memset(a, 0, sizeof(a));
    a[0] = b[0];
    for (int i = 1; i <= b[0]; i++)
        a[i] = b[i];
}

void print(int a[]) {
    for (int i = a[0]; i >= 1; i--)
        printf("%d", a[i]);
}