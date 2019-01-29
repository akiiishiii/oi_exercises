// 2068.cpp
#include <iostream>
#include <cctype>

int p[400005], mk[400005], n, len;
char ss[400005], s[400005], t;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while ((t = std::cin.get()) != (-1))
        ss[++n] = t;
    for (int i = 0; i <= n; i++) {
        if (isalpha(ss[i])) {
            mk[len] = i;
            if ('A' <= ss[i] && ss[i] <= 'Z')
                s[len++] = ss[i] - 'A' + 'a';
            else
                s[len++] = ss[i];
        }
    }
    int id = 0, k, maxlen = 0;
    for (int i = len - 1; i + 1; i--) {
        s[i + i + 1] = s[i];
        s[i + i + 2] = 0;
        mk[i + i + 1] = mk[i];
        s[i + i + 2] = '#';
    }
    s[0] = '#';
    s[len * 2] = '^';
    for (int i = 1; i <= len * 2; i++) {
        if (id + p[id] > i)
            p[i] = std::min(p[id + id - i], p[id] + id - i);
        else
            p[i] = 0;
        while (s[i - p[i]] == s[i + p[i]])
            p[i]++;
        if (p[i] + i > p[id] + id) {
            id = i;
        }
        if (p[id] > maxlen) {
            maxlen = p[id];
            k = i;
        }
    }
    int st = k - p[k] + 1 + (s[k - p[k] + 1] == '#'), ed = k + p[k] - 1 - (s[k + p[k] - 1] == '#');
    std::cout << (ed - st) / 2 + 1 << "\n";
    for (int i = mk[st]; i <= mk[ed]; i++)
        std::cout << ss[i];
    return 0;
}