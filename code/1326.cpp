// 1326.cpp
#include <iostream>

int poker[14][5], open[13];

inline bool chk(char c);
inline int get(char c);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int ans = 0;
    for (int i = 1; i <= 13; i++)
        for (int j = 4; j >= 1; j--) {
            char c = std::cin.get();
            while (chk(c))
                c = std::cin.get();
            poker[i][j] = get(c);
        }
    poker[13][0] = 4;
    while (poker[13][0]) {
        int k = poker[13][poker[13][0]];
        poker[13][0]--;
        while (k != 13) {
            open[k]++, poker[k][0]++;
            k = poker[k][poker[k][0]];
        }
    }
    for (int i = 1; i <= 12; i++)
        ans += (open[i] == 4);
    std::cout << ans << '\n';
    return 0;
}

inline bool chk(char c) {
    return !((c <= '9' && c >= '0') ||
             (c == 'A' || c == 'J' || c == 'Q' || c == 'K'));
}

inline int get(char c) {
    switch (c) {
    case 'A':
        return 1;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    case '0':
        return 10;
    default:
        return c - '0';
    }
}