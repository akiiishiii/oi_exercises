// 2320.cpp
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::string s;
    std::cin >> N;
    while (N--) {
        std::cin >> s;
        int i = 0, j = 1, k = 0;
        while (i < s.length() && j < s.length() && k < s.length()) {
            int x = s[(i + k) % s.length()] - s[(j + k) % s.length()];
            if (!x)
                k++;
            else {
                (x > 0 ? i : j) += k + 1;
                if (i == j)
                    i++;
                k = 0;
            }
        }
        int y = std::min(i, j);
        std::cout << y + 1 << '\n';
    }
    return 0;
}