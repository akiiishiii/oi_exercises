// 1332.cpp
#include <iostream>

int n;
int prt[30010], dis[30010], siz[30010];

int search(int k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 1; i <= 30000; i++)
        siz[i] = 1, prt[i] = i;
    std::cin >> n;
    while (n--) {
        char s[2];
        int x, y;
        std::cin >> s >> x >> y;
        int p1 = search(x), p2 = search(y);
        if (s[0] == 'M') {
            prt[p1] = p2;
            dis[p1] = siz[p2];
            siz[p2] += siz[p1];
        } else {
            if (p1 != p2)
				std::cout << "-1\n";
            else
				std::cout << std::abs(dis[x] - dis[y]) - 1 << '\n';
        }
    }
    return 0;
}

int search(int k) {
    if (prt[k] != k) {
        int f = search(prt[k]);
        dis[k] += dis[prt[k]];
        prt[k] = f;
    }
    return prt[k];
}

