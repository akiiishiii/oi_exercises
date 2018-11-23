// 1244_.cpp
#include <iostream>

int n;
int c[8010], a[8010];

inline int lowbit(int const x) { return x & (-x); }
void add(int x);
int sum(int x);
int binary_search(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    a[0] = 0;
    for (int i = 1; i < n; ++i)
        std::cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        int x = binary_search(a[i]);
        a[i] = x;
        add(x);
    }
    for (int i = 0; i < n; i++)
        std::cout << a[i] << '\n';
    return 0;
}

void add(int x) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i]++;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int binary_search(int x) {
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (mid - 1 - sum(mid) >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}