// hero.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

#define debug

#ifndef debug

std::ifstream in("hero.in");
std::ofstream out("hero.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

struct edge {
    int u;
    int v;
    int z;
};

struct compare : public std::binary_function<edge, edge, bool> {
    bool operator()(edge const &a, edge const &b) { return (a.z == b.z ? a.u < b.u : a.z < b.z); }
};

int n, k;
int prt[1001];
std::priority_queue<edge, std::vector<edge>, compare> q;

void merge(int a, int b);
int search(int a);
int chkcnt();

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
    in >> n >> k;
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1, tmp; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            in >> tmp;
        for (int j = i + 1; j <= n; j++) {
            in >> tmp;
            if (tmp)
                q.push((edge){i, j, tmp});
        }
    }
    edge now = q.top();
    while (true) {
        now = q.top();
        q.pop();
        merge(now.u, now.v);
        if (chkcnt() < k)
            break;
    }
    out << now.z << '\n';
    return 0;
}

void merge(int a, int b) {
    int fa = search(a), fb = search(b);
    if (fa != fb)
        prt[fa] = fb;
}

int search(int a) {
    if (prt[a] == a)
        return a;
    prt[a] = search(prt[a]);
    return prt[a];
}

int chkcnt() {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (prt[i] == i)
            cnt++;
    return cnt;
}