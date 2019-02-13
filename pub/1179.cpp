// 1179.cpp
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector< std::pair<int, int> > v;
    int m, n;
    read(n);
    read(m);
    m *= 3;
    m /= 2;
    for (int i = 0, k, s; i < n; i++) {
        read(k);
        read(s);
        v.push_back(std::make_pair(-s, k));
    }
    std::sort(v.begin(), v.end());
    int line = v[m - 1].first;
    for (int i = m; i < n; i++)
        if (v[i].first == line)
            m++;
        else
            break;
    write(-line);
    std::cout.put(' ');
    write(m);
    std::cout.put('\n');
    for (int i = 0; i < m; i++) {
        write(v[i].second);
        std::cout.put(' ');
        write(-v[i].first);
        std::cout.put('\n');
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