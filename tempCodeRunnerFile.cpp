// 1557.cpp
#include <algorithm>
#include <iostream>

struct tinp{
    long long p, q, r, b;
} a[101];

int n, root;
long long f[101];
bool p[101];

long long dfs(int x);
int main(int argc, char const *argv[]){
    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> a[i].p >> a[i].q >> a[i].r >> a[i].b;
        p[a[i].r]=true;
        p[a[i].b]=true;
    }
    for(int i = 1; i <= n; i++){
        if(!p[i]){
            root = i;
            break;
        }
    }
    std::cout << dfs(root);
    return 0;
}

long long dfs(int x) {
    int l = a[x].r, r = a[x].b;
    long long lmin = 1, rmin = 1;
    if(l)
        lmin = dfs(l);
    if(r)
        rmin = dfs(r);
    int ans = lmin * a[x].p * rmin * a[x].q / std::__gcd(lmin*a[x].p, rmin*a[x].q);
    return ans / a[x].p + ans / a[x].q; 
}