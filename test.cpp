// test.cpp
#include <iostream>
#include <cctype>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, sta;
    char c;
    std::cin >> n;
    std::cin.get(); // 第一行的换行符
    for (int i = 1; i <= n; i++) {
        sta = 0;
        while ((c = std::cin.get()) != '\n')
            if (isalpha(c))
                sta |= (1 << (tolower(c) - 'a'));
        if (sta == (1 << 26) - 1)
            std::cout << "pangram\n";
        else {
            std::cout << "missing ";
            for (int j = 0; j < 26; j++)
                if (!(sta & (1 << j)))
                    std::cout.put('a' + j);
            std::cout << '\n';
        }
    }
    return 0;
}