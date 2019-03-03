#include <bits/stdc++.h>
#define inf 0x7fffffff
//#define inline __attribute__((optimize("-inline")))
//#define getchar nc
namespace FastIO {
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 &&
                   (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
               ? EOF
               : *p1++;
}
inline int read() {
    char t;
    int u = 0, k = 1;
    t = getchar();
    while (t < '0' || t > '9') {
        if (t == '-')
            k = -1;
        t = getchar();
    }
    while (t >= '0' && t <= '9') {
        u = u * 10 + t - '0';
        t = getchar();
    }
    return u * k;
}
template <typename T> inline void read(T &u) {
    char t;
    T k = 1;
    u = 0;
    t = getchar();
    while (t < '0' || t > '9') {
        if (t == '-')
            k = -1;
        t = getchar();
    }
    while (t >= '0' && t <= '9') {
        u = u * 10 + t - '0';
        t = getchar();
    }
    if (t == '.') {
        T mass = 0.1;
        t = getchar();
        while (t >= '0' && t <= '9') {
            u += mass * (t - '0');
            mass /= 10;
            t = getchar();
        }
    }
    u *= k;
}
inline int read(char asd[]) {
    char t = getchar();
    int u = 0;
    while (t == ' ' || t == '\n')
        t = getchar();
    while (t != ' ' && t != '\n')
        asd[u++] = t, t = getchar();
    asd[u] = '\0';
    return u;
}
char sr[1 << 23], z[23];
int C = -1, Z;
inline void wer(int x, char T) {
    int y = 0;
    if (x < 0)
        y = 1, x = -x;
    while (z[++Z] = x % 10 + '0', x /= 10)
        ;
    if (y)
        z[++Z] = '-';
    while (sr[++C] = z[Z], --Z)
        ;
    sr[++C] = T;
}
inline void wer(char T[], char QWQ) {
    for (int i = 0; T[i] != '\0'; i++)
        sr[++C] = T[i];
    sr[++C] = QWQ;
}
inline void out() {
    fwrite(sr, 1, C + 1, stdout);
    C = -1;
}
} // namespace FastIO
using namespace std;
using namespace FastIO;
const int N = 100005;
int n, m, a, b, c, d, e, limit;
int main() { return out(), 0; }