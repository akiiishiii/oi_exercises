// 1473.cpp
#include <iostream>
#include <algorithm>

int search(int x, int p);

int main(int argc, char const * argv[]) {
    int n, tmp, ans, times, max_n;
    long long a, b;
    std::cin >> n;
    while (n--) {
        ans = 0;
        std::cin >> a >> b;
        times = a / 10000;
        max_n = a % 10000;
        for (int i = 1; i <= 9999; i++){
            tmp = search(i, b);
            if (i <= max_n) {
                ans = (ans + tmp * (times + 1)) % 10000;
            } else {
                ans = (ans + tmp * times) % 10000;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}

int search(int x, int p) {
    int ans = 1;
    while (p) {
        if (p & 1)
            ans = (ans * x) % 10000;
        x = (x * x) % 10000;
        p = p >> 1;
    }
    return ans;
}