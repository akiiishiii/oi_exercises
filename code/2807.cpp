// 2807.cpp
#include <iostream>
#include <cstring>

int n, m, tmp, ans;
int l, r;
int q[1005];
bool flag;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> m >> n;
    l = 1;
    r = ans = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        flag = false;
        for (int j = l; j <= r; j++)
            if (tmp == q[j]) {
                flag = true;
                break;
            }
        if (!flag) {
            ans++;
            q[++r]=tmp;
            while ((r - l + 1) > m)
                l++;
        }
    }
    std::cout << ans << '\n';
    return 0;    
}
