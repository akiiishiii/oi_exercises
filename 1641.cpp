// 1641.cpp
#include <iostream>

int phi(int n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n && n)
        std::cout << phi(n) << '\n';
    return 0;
}

int phi(int n) {
    int ans = n;
    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            ans = ans / i * (i-1);
            while (!(n % i))
                n /= i;
        }
    }
    if (n > 1)
        ans = ans / n * (n-1);
    return ans;
}