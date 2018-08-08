// prison.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

std::ifstream in("prison.in");
std::ofstream out("prison.out");

const int Maxmn = 100005;
int n, m, prt[Maxmn << 1];

struct data {
    int a, b, c;
    bool operator<(const data &x) const { return c > x.c; }
} e[Maxmn];

inline int search(int x) { return x == prt[x] ? x : prt[x] = search(prt[x]); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    for (int i = 1; i <= m; i++)
        in >> e[i].a >> e[i].b >> e[i].c;
    std::sort(e + 1, e + m + 1);
    for (int i = 1; i <= (n << 1); i++)
        prt[i] = i;
    for (int i = 1; i <= m; i++) {
        int a = e[i].a, b = e[i].b, c = e[i].c;
        int prta = search(a), prtb = search(b);
        if (prta == prtb) {
            out << c << '\n';
            return 0;
        }
        prt[prta] = search(b + n);
        prt[prtb] = search(a + n);
    }
    out << "0\n";
    return 0;
}