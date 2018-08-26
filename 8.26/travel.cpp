// travel.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>

std::ifstream in("travel.in");
std::ofstream out("travel.out");

const int N = 200050;
int ver[N << 1], Next[N << 1], head[N << 1];
int n, tot, maxx = 0;
std::pair<int, int> fir[N], sec[N];
bool vis[N];

void read(int &x);
void write(int x);
void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void update(int mx, int len, int num);
void upward(int mx, int len, int prt);
int downward(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    read(n);
    for (int i = 1, u, v; i < n; i++) {
        read(u);
        read(v);
        add(u, v);
        add(v, u);
    }
    downward(0);
    memset(vis, false, sizeof(vis));
    upward(0, 0, n);
    for(int i = 0; i < n; ++i)
        if(fir[i].first + sec[i].first == maxx) {
            write(i);
            out.put('\n');
        }
    return 0;
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

void update(int mx, int len, int num) {
    if(len > fir[mx].first) {
        sec[mx] = fir[mx];
        fir[mx] = std::make_pair(len, num);
    } else if(len > sec[mx].first)
        sec[mx] = std::make_pair(len, num);
}

void upward(int mx, int len, int prt) {
    update(mx, len, prt);
    maxx = std::max(maxx, fir[mx].first + sec[mx].first);
    vis[mx] = true;
    for (int i = head[mx]; i; i = Next[i]) {
        int y = ver[i];
        if (vis[y])
            continue;
        if (y != fir[mx].second)
            upward(y, 1 + fir[mx].first, mx);
        else
            upward(y, 1 + sec[mx].first, mx);
    }
}

int downward(int mx) {
    vis[mx] = true;
    for(int i = head[mx]; i; i = Next[i]) {
        int y = ver[i];
        if (!vis[y])
            update(mx, downward(y) + 1, y);
    }
    return fir[mx].first;
}