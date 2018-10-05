// commando.cpp
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("commando.in");
std::ofstream out("commando.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 1000005;
int q[Maxn], head, tail;
long long a, b, c, n;
long long s[Maxn] = {0}, f[Maxn] = {0};

double slope(long long j, long long k) { return (((((f[k] - f[j]) * 1.0 / (s[k] - s[j])) - b) * 1.0 / a) + (s[k] + s[j]) * 1.0); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> a >> b >> c;
    long long tmp;
    for (int i = 1; i <= n; i++)
        in >> tmp, s[i] = s[i - 1] + tmp;
    head = tail = 1;
    f[0] = q[1] = 0;
    for (int i = 1; i <= n; i++) {
        while (head < tail && slope(q[head], q[head + 1]) <= 2 * s[i])
            head++;
        f[i] = f[q[head]] + a * (s[i] - s[q[head]]) * (s[i] - s[q[head]]) + b * (s[i] - s[q[head]]) + c;
        while (head < tail && slope(q[tail - 1], q[tail]) >= slope(q[tail], i))
            tail--;
        q[++tail] = i;
    }
    out << f[n] << '\n';
    return 0;
}
