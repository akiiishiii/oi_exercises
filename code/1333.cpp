// 1333.cpp
#include <iostream>

int prt[200000];
int n, m, k, x, y, ans;

int search(int x) { return prt[x] == x ? x : prt[x] = search(prt[x]);} 

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= 3 * n; i++)
		prt[i] = i;
    for (int i = 1; i <= m; i++) {
        std::cin >> k >> x >> y;
        if (x > n || y > n)
			ans++;
        else if(k == 1) {
            if (search(x) == search(y + n) || search(x) == search(y + n + n))
				ans++;
            else {
                prt[search(x)] = search(y);
                prt[search(x + n)] = search(y + n);
                prt[search(x + n + n)] = search(y + n + n);
            }
        } else {
            if (x == y || search(x) == search(y) || search(x) == search(y + n))
				ans++;
            else {
                prt[search(x)] = search(y + n + n);
                prt[search(x + n)] = search(y);
                prt[search(x + n + n)] = search(y + n);
            }
        }
    }
    std::cout << ans << '\n';
	return 0;
}
