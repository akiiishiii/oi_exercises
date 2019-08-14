// pack.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("pack.in");
std::ofstream out("pack.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

struct A {
    int a, b;
} oa[105];

struct B {
    int a, b, c;
} ob[105];

struct C {
    int a, b;
} oc[105];

int f[2005];
int x, m, n, cnta, cntb, cntc;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> m >> n;
    for (int i = 1; i <= m; i++) {
        in >> x;
        if (x == 1) {
            cnta++;
            in >> oa[cnta].a >> oa[cnta].b;
        } else if (x == 2) {
            cntb++;
            in >> ob[cntb].a >> ob[cntb].b >> ob[cntb].c;
        } else {
            cntc++;
            in >> oc[cntc].a >> oc[cntc].b;
        }
    }
    for (int i = 1; i <= cnta; i++)
        for (int k = n; k >= 1; k--)
            for (int j = k; j >= 1; j--)
                f[k] = std::max(f[k], f[k - j] + j * j * oa[i].a - oa[i].b * j);
    for (int i = 1; i <= cntb; i++)
        for (int j = 0; j < ob[i].c; j++)
            for (int k = n; k >= ob[i].b; k--)
                f[k] = std::max(f[k], f[k - ob[i].b] + ob[i].a);
    for (int i = 1; i <= cntc; i++)
        for (int j = oc[i].b; j <= n; j++)
            f[j] = std::max(f[j], f[j - oc[i].b] + oc[i].a);
    out << f[n] << '\n';
    return 0;
}