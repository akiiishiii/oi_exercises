// 1200_.cpp
#include <iostream>
#include <string>

int c[100005] = {0};
int n;

void read(int &x);
void write(int x);
template <typename T>
inline T lowbit(T const &x) { return x & (-x); }
void add(int x, int d);
int sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m;
    char ch;
    read(n);
    read(m);
    for (int i = 1, x, y; i <= m; i++) {
        std::cin.get(ch);
        std::cin.get(ch);
        std::cin.get(ch);
        std::cin.get(ch);
        read(x);
        read(y);
        if (ch == 'd')
            add(x, y);
        else if (ch == 'b')
            add(x, -y);
        else {
            write(sum(y) - sum(x - 1));
            std::cout.put('\n');
        }
    }
    return 0;
}

void read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

void write(int x) {
    if (x < 0) {
        std::cout.put('-');
        x = -x;
    }
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        std::cout.put(x / y + 48);
        x %= y;
    }
}

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