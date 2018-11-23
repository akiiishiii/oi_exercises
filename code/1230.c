// 1230.c
#include <stdio.h>
#include <math.h>

#define MAXN 100005
int n;
long long a[MAXN], c[MAXN], prt[MAXN];

int lowbit(int const x) { return x & (-x); }
int search(int const x) { return (x[prt] == x) ? x : (x[prt] = search(x[prt])); }
void add(int x, long long d);
long long sum(int x);

int main(int argc, char const *argv[]) {
    int m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i), add(i, i[a]), i[prt] = i;
    scanf("%d", &m);
    for (int i = 1, k, l, r; i <= m; i++) {
        scanf("%d %d %d", &k, &l, &r);
        if (k)
            printf("%lld\n", sum(r) - sum(l - 1));
        else {
            for (int i = l, t; i <= r; i++) {
                i = search(i);
                if (i > r)
                    break;
                add(i, (t = (int)sqrt((double)i[a])) - i[a]);
                i[a] = t;
                if (i[a] == 1)
                    i[prt] = (i + 1)[prt];
            }
        }
    }
    return 0;
}

void add(int x, long long d) {
    for (int i = x; i <= MAXN; i += lowbit(i))
        c[i] += d;
    return;
}

long long sum(int x) {
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}