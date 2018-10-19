// 1919.cpp
#include <iostream>
#include <vector>
#include <string>

struct node {
    int son[26] = {0};
    bool end = false;
    node() = default;
    ~node() = default;
} tree[30000];
int cnt = 0;
void insert(std::string &s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    while (std::cin >> s)
        ::insert(s);
    std::cout << cnt + 1 << '\n';
    return 0;
}

void insert(std::string &s) {
    node *p = &tree[0];
    for (auto&& it : s) {
        if (it == '\0')
            break;
        int c = it - 'A';
        if (!(p->son[c]))
            p->son[c] = ++cnt;
        p = &tree[p->son[c]];
    }
    p->end = true;
}