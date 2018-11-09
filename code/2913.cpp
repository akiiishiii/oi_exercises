// 2913.cpp
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    int t, dx = 0, dy = 0, x = 0, y = 0;
    std::cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'N')
            dy++;
        else if (s[i] == 'S')
            dy--;
        else if (s[i] == 'E')
            dx++;
        else if (s[i] == 'W')
            dx--;
    }
    std::cin >> t;
    int tmp = t / s.length();
    t %= s.length();
    x += tmp * dx, y += tmp * dy;
    for (int i = 0; i < t; i++) {
        if (s[i] == 'N')
            y++;
        else if (s[i] == 'S')
            y--;
        else if (s[i] == 'E')
            x++;
        else if (s[i] == 'W')
            x--;
    }
    std::cout << x << ' ' << y << '\n';
    return 0;
}
