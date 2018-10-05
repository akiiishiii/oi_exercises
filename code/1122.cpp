// 1122.cpp
#include <iostream>

int f[35][35];

int calc(int x, int k);
int work(int x, int b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    f[0][0] = 1;
    for (int i = 1; i <= 31; i++) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
    }
    int x, y, k, b;
    std::cin >> x >> y >> k >> b;
    if (b == 2)
        std::cout << calc(y, k) - calc(x - 1, k) << '\n';
    else
        std::cout << calc(work(y, b), k) - calc(work(x, b) - 1, k) << '\n';
    return 0;
}

int calc(int x, int k) {
    int ans = 0, tot = 0;
    for (int i = 31; i > 0; i--) {
        if (x & (1 << i)) {
            tot++;
            if (tot > k)
                break;
            x ^= (1 << i);
        }
        if (1 << (i - 1) <= x)
            ans += f[i - 1][k - tot];
    }
    if (tot + x == k)
        ans++;
    return ans;
}

int work(int x, int b) {
    int a[35] = {0};
    int ans = 0, i = 0;
    while (x > 0) {
        a[++i] = x % b;
        x /= b;
    }
    int j = i;
    while (a[i] <= 1)
        i--;
    while (i >= 1)
        a[i--] = 1;
    while (j >= 1)
        ans = ans * 2 + a[j--];
    return ans;
}