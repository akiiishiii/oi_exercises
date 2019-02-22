// 3403.cpp
#include <iostream>

int n, a[300005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int x = a[(i + k) % n] - a[(j + k) % n];
        if (!x)
            k++;
        else {
            (x > 0 ? i : j) += k + 1;
            if (i == j)
                i++;
            k = 0;
        }
    }
    int y = std::min(i, j);
    for (int i = 0; i <= n - 1; i++)
        std::cout << a[(i + y) % n] << ' ';
    std::cout << '\n';
    return 0;
}