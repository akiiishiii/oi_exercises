// 1330.cpp
#include <iostream>

long long a[2000005] = {0}, b[200005] = {0};

int main(int argc, const char * argv[]) {
    int n, l = 1, r = 1;
    long long s, sum = 2000005;
    std::cin >> n >> s;
    std::cin >> a[1];
    b[1] = a[1];
    for (int i = 2; i <= n; i++) {
        std::cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    while (l <= r && l <= n && r <= n) {
        if (b[r] - b[l - 1] < s)
            r++;
        else if (b[r] - b[l - 1] >= s) {
            sum = (r - l + 1) > sum ? sum : (r - l + 1);
            l++;
        }
    }
    std::cout << sum << '\n';
    return 0;
}