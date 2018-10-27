// median.cpp
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("median.in");
std::ofstream out("median.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

struct {
    int l, r;
} e[200005];
int arr[100005], d[100005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n, b, pos;
    long long ans = 0;
    in >> n >> b;
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        in >> arr[i];
        if (arr[i] == b)
            d[i] = 0 + d[i - 1], pos = i;
        else
            d[i] = (arr[i] > b ? 1 : -1) + d[i - 1];
    }
    /*
    for (int i = pos; i > 0; i--)
        for (int j = pos + ((pos - i) & 1); j <= n; j += 2)
            if (!(d[j] - d[i - 1]))
                ans++;
    */
    for (int i = 0; i < pos; i++)
        e[d[i] + n].l++;
    for (int i = pos; i <= n; i++)
        e[d[i] + n].r++;
    for (int i = 0; i <= n << 1; i++)
        ans += (long long)e[i].l * e[i].r;
    out << ans << '\n';
    return 0;
}