// 1028.cpp
#include <iostream>

int a[5010], f[5010], num[5010];
int n, maxx = 0, sum = 0;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            if (a[i] < a[j])
                f[i] = std::max(f[i], f[j] + 1);
        if (!f[i])
            f[i] += 1;
        maxx = std::max(maxx, f[i]);
        for (int j = 1; j < i; j++)
            if (f[i] == f[j] && a[i] == a[j])
                num[j] = 0;
            else if (f[i] == f[j] + 1 && a[i] < a[j])
                num[i] += num[j];
        if (!num[i])
            num[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (f[i] == maxx)
            sum += num[i];
    std::cout << maxx << ' ' << sum << '\n';
    return 0;
}