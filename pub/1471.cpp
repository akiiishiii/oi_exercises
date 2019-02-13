// 1471.cpp
#include <iostream>
#include <cmath>

inline long long digit(long long a) { return (long long)(a * log10(a)) + 1LL; }
int binary_search(long long l, long long r, int target);

int main(int argc, char const * argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::cout << binary_search(1, 0x3F3F3F3F, n) << '\n';
    return 0;
}

int binary_search(long long l, long long r, int target) {
    long long mid, ans;
    while (l <= r) {
        mid = (l + r) / 2;
        if (target <= digit(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}