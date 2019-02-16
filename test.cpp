#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define MAX 100005
#define INF 0x3f3f3f3f3f
using namespace std;
int n, L, P, point, a;
long double f[MAX], s[MAX];
char str[MAX];
struct node {
    int l, r, p;
};
deque<node> q;
// inline char nc()
//{
//	static char buf[100000],*p1=buf,*p2=buf;
//	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline char nc() { return getchar(); }
inline long long read() {
    char t;
    long long u = 0, k = 1;
    t = nc();
    while (t < '0' || t > '9') {
        if (t == '-')
            k = -1;
        t = nc();
    }
    while (t >= '0' && t <= '9') {
        u = u * 10 + t - '0';
        t = nc();
    }
    return u * k;
}
long double Abs(long double x) { return x > 0 ? x : -x; }
long double quick_power(long double x, int y) {
    long double re = 1;
    while (y) {
        if (y & 1)
            re = re * x;
        x = x * x;
        y >>= 1;
    }
    return re;
}
long double get(int l, int r) {
    return f[l] +
           quick_power(Abs((long double)(s[r] - s[l] + (r - l - 1) - L)), P);
}
long double find(node x, int y) {
    int l = x.l, r = x.r, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (get(x.p, mid) < get(y, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}
int main() {
    int T;
    T = read();
    while (T--) {
        while (q.size())
            q.pop_back();
        n = read();
        L = read();
        P = read();
        point = 0;
        for (int i = 1; i <= n; i++)
            scanf("%s", str), a = strlen(str), s[i] = s[i - 1] + a;
        node st;
        st.l = 0;
        st.p = 0;
        st.r = n;
        q.push_back(st);
        for (int i = 1; i <= n; i++) {
            if (q.size() && i > q.front().r)
                q.pop_front();
            f[i] = get(q.front().p, i);
            if (q.empty() || get(i, n) <= get(q.back().p, n)) {
                while (q.size() &&
                       get(i, q.back().l) <= get(q.back().p, q.back().l))
                    q.pop_back();
                if (q.empty()) {
                    node in;
                    in.l = i;
                    in.r = n;
                    in.p = i;
                    q.push_back(in);
                } else {
                    int pos = find(q.back(), i);
                    node in;
                    q.back().r = pos - 1;
                    in.l = pos;
                    in.r = n;
                    in.p = i;
                    q.push_back(in);
                }
            }
        }
        if (f[n] > 1000000000000000000ll)
            printf("Too hard to arrange\n");
        else
            printf("%lld\n", (long long)f[n]);
    }
    return 0;
}