// tree.cpp
#include <iostream>
#include <fstream>
#include <algorithm>

std::ifstream in("tree.in");
std::ofstream out("tree.out");

struct citizen {
    int b;
    int e;
    int t;
    int now = 0;
    bool operator<(citizen const &c) const { return e < c.e; }
} c[5001];

bool mark[30001] = {false};
int n, m, cnt = 0;

void set(int mx, int mi);
void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    read(n);
    read(m);
    for (int i = 1; i <= m; i++) {
        read(c[i].b);
        read(c[i].e);
        read(c[i].t);
    }
    std::sort(c + 1, c + m + 1);
    for (int i = 1; i <= m; i++)
        for (int k = c[i].e; k >= c[i].b && c[i].now < c[i].t; k--)
            if (!mark[k])
                set(k, i);
    write(cnt);
    out.put('\n');
    return 0;
}

void set(int mx, int mi) {
    bool flag = true;
    for (int i = mi; i <= m; i++)
        if (mx >= c[i].b && mx <= c[i].e) {
            if (flag) {
                mark[mx] = true, cnt++;
                flag = false;
            }
            c[i].now++;
        }
}

void read(int &x) {
    x = 0;
    char c = in.get();
    while (c < '0' || c > '9')
        c = in.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = in.get();
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
        out.put(x / y + 48);
        x %= y;
    }
}