// 1509.cpp
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

struct work {
    work() = default;
    ~work() = default;
    int a;
    int b;
    int v;
    friend std::istream &operator>>(std::istream &is, work &w);
};

struct compb : public std::binary_function<work, work, bool> {
    bool operator()(work const &wa, work const &wb) { return wa.b < wb.b; }
};

int main(int argc, char const *argv[]) {
    std::vector<work> ws;
    std::vector<int> f;
    int n, m = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        ws.push_back(work());
        std::cin >> ws[i];
        m = std::max(m, ws[i].b);
    }
    f.resize(m + 1);
    std::sort(ws.begin(), ws.end(), compb());
    for (int i = 0, j = 1; j <= m; j++) {
        f[j] = f[j - 1];
        while (ws[i].b == j) {
            f[j] = std::max(f[j], f[ws[i].a] + ws[i].v);
            i++;
        }
    }
    std::cout << f[m] << '\n';
    return 0;
}

std::istream &operator>>(std::istream &is, work &w) {
    is >> w.a >> w.b >> w.v;
    return is;
}