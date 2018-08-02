// 1319.cpp
#include <iostream>
#include <algorithm>

int main(int argc, char const * argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    int a[100005] = {0};
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::cin >> k;
    std::sort(a, a + n);
    for (int i = n - 1; i > n - 1 - k; i--)
        std::cout << a[i] << '\n';
    return 0;
}