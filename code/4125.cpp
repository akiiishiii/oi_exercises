// 4125.cpp
#include <iostream>
#include <cmath>
#include <complex>
#include <string>

int const Maxn = 1000005;
std::complex<double> wi[Maxn], a[Maxn], b[Maxn];
int c[Maxn], rev[Maxn], len, n;
std::string qwe;

int make(int n);
void dft(std::complex<double> a[], int n, int f);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> qwe;
    for (int i = 0; qwe[i]; i++)
        a[n - i - 1] = qwe[i] - '0';
    std::cin >> qwe;
    for (int i = 0; qwe[i]; i++)
        b[n - i - 1] = qwe[i] - '0';
    int m = make(n * 2 + 2);
    dft(a, m, 1);
    dft(b, m, 1);
    for (int i = 0; i < m; i++)
        a[i] *= b[i];
    dft(a, m, -1);
    for (int i = 0; i < m; i++)
        c[i] = a[i].real() + 0.1;
    for (int i = 0; i < m; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (!c[m])
        m--;
    for (int i = m; i >= 0; i--)
        std::cout.put(c[i] + '0');
    std::cout << '\n';
    return 0;
}

int make(int n) {
    int l = log2(n) + 1;
    n = (1 << l);
    for (int i = 1; i < n; i++)
        rev[i] = rev[i >> 1] >> 1 | ((i & 1) << (l - 1));
    return n;
}

void dft(std::complex<double> a[], int n, int f) {
    for (int i = 0; i < n; i++)
        if (rev[i] < i)
            std::swap(a[i], a[rev[i]]);
    for (int i = 1; i < n; i <<= 1) {
        std::complex<double> wn = exp(std::complex<double>(0, f * 3.14159 / i));
        wi[0] = 1;
        for (int j = 1; j < i; j++)
            wi[j] = wi[j - 1] * wn;
        for (int j = 0; j < n; j += (i << 1)) {
            for (int v = 0; v < i; v++) {
                std::complex<double> x = a[j + v], y = a[j + v + i] * wi[v];
                a[j + v] = x + y;
                a[j + v + i] = x - y;
            }
        }
    }
    if (f == -1)
        for (int i = 0; i < n; i++)
            a[i] /= n;
}