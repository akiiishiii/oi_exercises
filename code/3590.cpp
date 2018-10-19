// 3590.cpp
#include <iostream>
#include <vector>
#include <string>

struct node {
    int son[26] = {0};
    std::string meaning = "eh";
    node() = default;
    ~node() = default;
} tree[1000005];
int cnt = 0;
void insert(std::string &s, std::string &m);
std::string search(std::string &s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s, tmp;
    std::cin >> s >> tmp;
    while (true) {
        ::insert(tmp, s);
        char c = std::cin.get();
        c = std::cin.get();
        if (c == '\n')
            break;
        std::cin >> s >> tmp;
        s = c + s;
    }
    while (std::cin >> s)
        std::cout << ::search(s) << '\n';
    return 0;
}

void insert(std::string &s, std::string &m) {
    node *p = &tree[0];
    for (auto&& it : s) {
        if (it == '\0')
            break;
        int c = it - 'a';
        if (!(p->son[c]))
            p->son[c] = ++cnt;
        p = &tree[p->son[c]];
    }
    p->meaning = m;
}

std::string search(std::string &s) {
    node *p = &tree[0];
    for (auto&& it : s) {
        if (it == '\0')
            break;
        int c = it - 'a';
        if (!(p->son[c]))
            return std::string("eh");
        p = &tree[p->son[c]];
    }
    return p->meaning;
}