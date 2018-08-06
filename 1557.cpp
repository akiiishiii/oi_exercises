// 1557.cpp
#include <algorithm>
#include <iostream>

struct tp{
    long long p, q, r, b;
} a[105];

long long dfs(long long x);
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char const *argv[]){
    int n, root = 0;
    bool p[105];
    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> a[i].p >> a[i].q >> a[i].r >> a[i].b;
        p[a[i].r] = true;
        p[a[i].b] = true;
    }
    for(int i = 1; i <= n; i++){
        if(!p[i]){
            root = i;
            break;
        }
    }
    std::cout << dfs(root) << '\n';
    return 0;
}

long long dfs(long long x) {
    long long l = a[x].r, r = a[x].b;
    long long lmin = 1, rmin = 1;
    if (l)
        lmin = dfs(l);
    if (r)
        rmin = dfs(r);
    long long ans = lmin * a[x].p * rmin * a[x].q / gcd(lmin * a[x].p, rmin * a[x].q);
    return ans / a[x].p + ans / a[x].q;
}
