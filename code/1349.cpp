// 1349.cpp
#include <cstring>
#include <iostream>

char const Num[] =
    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char s1[10001], s2[10001];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T, a, b, len;
    std::cin >> T;
    while (T--) {
        int k, res, j;
        std::cin >> a >> b >> s1;
        std::cout << a << ' ' << s1 << '\n';
        len = strlen(s1);
        bool flag = true;
        j = 0;
        while (flag) {
            flag = false;
            res = 0;
            for (int i = 0; i < len; i++) {
                if (s1[i] >= '0' && s1[i] <= '9')
                    k = s1[i] - '0';
                if (s1[i] >= 'A' && s1[i] <= 'Z')
                    k = s1[i] - 'A' + 10;
                if (s1[i] >= 'a' && s1[i] <= 'z')
                    k = s1[i] - 'a' + 36;
                k = res * a + k;
                res = k % b;
                s1[i] = Num[k / b];
                if (s1[i] != '0')
                    flag = true;
            }
            s2[j++] = Num[res];
        }
        std::cout << b << ' ';
        for (int i = j - 1; i >= 0; i--)
            std::cout << s2[i];
        std::cout << "\n\n";
    }
    return 0;
}