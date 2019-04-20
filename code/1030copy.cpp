
#include <cstdio>
#include <iostream>
using namespace std;
int n, t, a[100005];
long long sum[100005], f[100005], q[100005], head, tail;
long long read() {
    long long s = 0;
    char ch = getchar();
    int f = 1;
    while (ch < '0' || ch > '9')
        f = (ch == '-' ? -1 : 1), ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * f;
}
void write(long long s) {
    if (s < 0) {
        putchar('-');
        write(-s);
        return;
    }
    if (s > 9)
        write(s / 10);
    putchar(s % 10 + '0');
}
long double s(int j, int k) {
    return ((f[j] - sum[j] * j) - (f[k] - sum[k] * k)) / ((long double)(k - j));
}
int main() {
    n = read();
    t = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
    }
    f[0] = 0;
    head = tail = 1;
    q[head] = 0;
    for (int i = 1; i <= n; i++) {
        while (head < tail && (s(q[head], q[head + 1]) <= sum[i]))
            head++;
        f[i] = f[q[head]] + (sum[i] - sum[q[head]]) * q[head] - t;
        while (head < tail && s(q[tail - 1], q[tail]) >= s(q[tail], i))
            tail--;
        q[++tail] = i;
    }
    write(f[n]);
    return 0;
}