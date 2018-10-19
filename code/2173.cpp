// 2173.cpp
#include <iostream>
#include <vector>
#include <string>

struct node {
    int son[26] = {0};
    int end = 0;
    node() = default;
    ~node() = default;
} tree[1000005];
int cnt = 0;
void insert(std::string &s, int page);
int search(std::string &s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::string s;
    std::cin >> n;
    for (int i = 0, tmp; i < n; i++) {
        std::cin >> s >> tmp;
        ::insert(s, tmp);
    }
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> s;
        std::cout << ::search(s) << '\n';
    }
    return 0;
}

void insert(std::string &s, int page) {
    node *p = &tree[0];
    for (auto&& it : s) {
        if (it == '\0')
            break;
        int c = it - 'a';
        if (!(p->son[c]))
            p->son[c] = ++cnt;
        p = &tree[p->son[c]];
    }
    p->end = page;
}

int search(std::string &s) {
    node *p = &tree[0];
    for (auto&& it : s) {
        if (it == '\0')
            break;
        int c = it - 'a';
        p = &tree[p->son[c]];
    }
    return p->end;
}