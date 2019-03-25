#include <iostream>
#include <bitset>

std::bitset<25005> laugh, vis[25005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    while (m--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, l, k;
            std::cin >> x >> l >> k;
            for (int i = std::max(1, x - k); i <= std::min(n, x + k); i++) {
                if (vis[i].test(l))
                    laugh.set(i, 0);
                else
                    laugh.set(i, 1), vis[i].set(l, 1);
            }
        } else {
            int ret = 0, l, r;
            std::cin >> l >> r;
            for (int i = l; i <= r; i++)
                if (laugh.test(i))
                    ret++;
            std::cout << ret << '\n';
        }
    }
    return 0;
}