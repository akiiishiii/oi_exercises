// 1285.cpp
#include <iostream>
#include <cstring>

int x[256];
int pieces[30001];
int m, n, i, j;

int main(int argc, const char * argv[]) {
    std::cin >> m >> n;
    for (i = 1; i <= m; i++)
        std::cin >> x[i];
    memset(pieces, 0, sizeof pieces);
    int maxx = 0;
    do {
        maxx++;
        for (i = 1; i <= m; i++)
            if (maxx - x[i] >= 0) {
                    if (pieces[maxx] == 0)
                        pieces[maxx] = pieces[maxx - x[i]] + 1;
                    if (pieces[maxx] > pieces[maxx - x[i]] + 1)
                        pieces[maxx] = pieces[maxx - x[i]] + 1;
                }
        if ((pieces[maxx] == 0) || (pieces[maxx] > n)) {
            std::cout << maxx - 1;
            break;
        }

    } while (true);
    return 0;
}