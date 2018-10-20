// robot.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("robot.in");
std::ofstream out("robot.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m1, m2, len1 = 1, len2 = 1, ans;
std::vector<int> p, f1, f2;

//template <typename T1, typename T2>
//auto max(T1 const &a, T2 const &b) -> decltype(a > b ? a : b) { return a > b ? a : b; }

inline void read(int &x);
inline void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    ::read(n);
    ::read(m1);
    ::read(m2);
    p.resize(n + 1);
    f1.resize(n + 1);
    f2.resize(n + 1);
    for (int i = 1; i <= n; i++)
        ::read(p[i]);
    f1[1] = f2[1] = p[1];
    for (int i = 2; i <= n; i++) {
        int l = 1, r = len1;
        if (f1[len1] <= p[i]) {
            len1++;
            f1[len1] = p[i];
            continue;
        }
        while (l <= r) {
            int mid = (l + r) / 2;
            if (f1[mid] <= p[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
        f1[l] = p[i];
    }
    for (int i = 2; i <= n; i++) {
        int l = 1, r = len2;
        if (f2[len2] >= p[i]) {
            len2++;
            f2[len2] = p[i];
            continue;
        }
        while (l <= r) {
            int mid = (l + r) / 2;
            if (f2[mid] >= p[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
        f2[l] = p[i];
    }
    /* O(n^2)
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            if (p[i] >= p[j])
                f1[i] = std::max(f1[i], f1[j] + 1);
        len1 = std::max(len1, f1[i]);
    }
    p[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            if (p[i] <= p[j])
                f2[i] = std::max(f2[i], f2[j] + 1);
        len2 = std::max(len2, f2[i]);
    }
    */
    if (len1 == n || len2 == n)
        ans = 0;
    else if (m1 == m2)
        ans = m1 * (n - std::max(len1, len2));
    else {
        ans = std::min(std::min(m1 * (n - len1), m2 * (n - len1)), std::min(m1 * (n - len2), m2 * (n - len2)));
    }
    write(ans);
    out.put('\n');
    return 0;
}

inline void read(int &x) {
    x = 0;
    char c = in.get();
    while (c < '0' || c > '9')
        c = in.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = in.get();
    }
}

inline void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        out.put(x / y + 48);
        x %= y;
    }
}