// 1144.cpp
#include <iostream>
#include <cstring>

long long f[500005] = {0}, s[500005] = {0};
int q[1000000] = {0};
int m, n;

inline double slope(int i, int j) { return double(f[j] + s[j] * s[j] - (f[i] + s[i] * s[i])) / (2 * s[j] - 2 * s[i]); }
void dp();

int main(int argc, char const *argv[]) {
    while (std::cin >> n >> m) {
        for (int i = 1, tmp; i <= n; i++) {
            std::cin >> tmp;
            s[i] = tmp + s[i - 1];
        }
        dp();
        std::cout << f[n] << '\n';
    }
    return 0;
}


void dp() {
    int l = 1, r = 1;
    q[1] = f[0] = 0;
    for (int i = 1; i <= n; i++) {
        while (l < r && slope(q[l], q[l + 1]) < s[i])
            l++;
        int j = q[l];
        f[i] = f[j] + (s[i] - s[j]) * (s[i] - s[j]) + m;
        while (l < r && slope(q[r - 1], q[r]) >= slope(q[r], i))
            r--;
        q[++r] = i;
    }
}