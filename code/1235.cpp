// 1235.cpp
#include <iostream>

template <typename T> inline T lowbit(T const x) { return x & (-x); }
void add(int x, int d);
int sum(int x);

int main(int argc, char const *argv[]) { return 0; }

void add(int x, int d) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += d;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}