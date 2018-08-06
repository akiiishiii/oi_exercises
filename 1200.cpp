// 1200.cpp
#include <iostream>
#include <string>

std::string s;

void maketree(int x, int y);

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n >> s;
    maketree(0, (1 << n) - 1);
    std::cout << '\n';
    return 0;
}

void maketree(int x, int y) {
    if (y > x) {
        maketree(x, (x + y) / 2);
        maketree((x + y + 1) / 2, y);
    }
    int B = 1, I = 1;
    for (int i = 0; i <= y - x; i++) {
        if (s[x + i] == '1') {
            B = 0;
        } else if (s[x + i] == '0') {
            I=0;
        }
    }
    if (B) {
        std::cout << 'B';
    } else if (I) {
        std::cout << 'I';
    } else {
        std::cout << 'F';
    }
}
